"""Functions to help with Jacobian calculations."""

import numpy as np
from scipy.linalg import logm

from jenga.kin_func_skeleton import (
    R3_to_so3,
    forward_kinematics,
    inverse_SE3,
    se3_to_twist,
    twist_to_SE3,
)


def adjoint(g):
    """Calculate the adjoint matrix of a rigid transformation.

    Args:
        g: NumPy array with shape ``(4, 4)`` representing a
            transformation in SE(3).

    Returns:
        NumPy array with shape ``(6, 6)`` representing ``Ad_g``.
    """

    # TODO
    R = g[:3, :3]
    p = g[:3, 3]
    p_hat = R3_to_so3(p)

    top = np.hstack((R, p_hat @ R))
    bottom = np.hstack((np.zeros((3,3)), R))

    return np.vstack((top, bottom))


def adjoint_inv(g):
    """Calculate the inverse adjoint matrix of a rigid transformation.

    Args:
        g: NumPy array with shape ``(4, 4)`` representing a
            transformation in SE(3).

    Returns:
        NumPy array with shape ``(6, 6)`` representing ``Ad_g^{-1}``.
    """

    # TODO
    return adjoint(inverse_SE3(g))


def spatial_jacobian(twists, theta):
    """Calculate the spatial manipulator Jacobian.

    Args:
        twists: NumPy array with shape ``(6, N)`` whose columns are the
            spatial twists of the joints at the home configuration.
        theta: NumPy array with shape ``(N,)`` containing the joint values.

    Returns:
        NumPy array with shape ``(6, N)`` containing the spatial Jacobian at
        ``theta``.
    """

    # TODO
    adj = np.eye(6)
    output_list = []
    twists = twists.T
    
    for i in range(twists.shape[0]):
        output_list.append(adj @ twists[i])
        adj = adj @ adjoint(twist_to_SE3(twists[i].T, theta[i]))

    return np.column_stack(output_list)



def body_jacobian(twists, theta, g_st0):
    """Calculate the body manipulator Jacobian.

    Args:
        twists: NumPy array with shape ``(6, N)`` whose columns are the
            spatial twists of the joints at the home configuration.
        theta: NumPy array with shape ``(N,)`` containing the joint values.
        g_st0: NumPy array with shape ``(4, 4)`` containing the end-effector
            pose at the home configuration.

    Returns:
        NumPy array with shape ``(6, N)`` containing the body Jacobian at
        ``theta``.
    """

    # TODO
    g = forward_kinematics(twists, theta)
    g_sttheta = g @ g_st0

    return adjoint_inv(g_sttheta) @ spatial_jacobian(twists, theta)


def spatial_velocity(twists, theta, theta_dot):
    """Calculate the spatial end-effector velocity.

    Args:
        twists: NumPy array with shape ``(6, N)`` whose columns are the
            spatial twists of the joints at the home configuration.
        theta: NumPy array with shape ``(N,)`` containing the joint values.
        theta_dot: NumPy array with shape ``(N,)`` containing the joint
            velocities.

    Returns:
        NumPy array with shape ``(6,)`` containing the spatial velocity.
    """

    # TODO
    return spatial_jacobian(twists, theta) @ theta_dot


def body_velocity(twists, theta, theta_dot, g_st0):
    """Calculate the body end-effector velocity.

    Args:
        twists: NumPy array with shape ``(6, N)`` whose columns are the
            spatial twists of the joints at the home configuration.
        theta: NumPy array with shape ``(N,)`` containing the joint values.
        theta_dot: NumPy array with shape ``(N,)`` containing the joint
            velocities.
        g_st0: NumPy array with shape ``(4, 4)`` containing the end-effector
            pose at the home configuration.

    Returns:
        NumPy array with shape ``(6,)`` containing the body velocity.
    """

    # TODO
    return body_jacobian(twists, theta, g_st0) @ theta_dot


def spatial_configuration_error(pose, desired_pose):
    """Calculate the spatial-frame transformation error.

    Args:
        pose: NumPy array with shape ``(4, 4)`` for the current SE(3) pose.
        desired_pose: NumPy array with shape ``(4, 4)`` for the desired
            SE(3) pose, expressed in the same reference frame.

    Returns:
        NumPy array with shape ``(4, 4)`` containing our error.
    """

    # TODO
    return desired_pose @ inverse_SE3(pose)


def spatial_error_twist(error):
    """Convert a transformation error into an exponential-coordinate vector.

    Args:
        error: NumPy array with shape ``(4, 4)`` in SE(3), returned by
            ``spatial_configuration_error``. Assume its rotation angle is less than pi.

    Returns:
        NumPy array with shape ``(6,)`` containing ``log(error)^vee``.

    Use ``scipy.linalg.logm`` for the matrix logarithm.
    """

    # TODO
    log = logm(error)
    return se3_to_twist(log)


def jacobian_inverse_kinematics(
    twists, theta, g_st0, desired_pose, step_size=0.2,
    max_iterations=200, tolerance=1e-6,
):
    """Solve inverse kinematics using spatial errors and forward-Euler updates.

    Args:
        twists: NumPy array with shape ``(6, N)`` containing the joint twists
            at the home configuration.
        theta: NumPy array with shape ``(N,)`` containing the initial joint values.
        g_st0: NumPy array with shape ``(4, 4)`` containing the home tool pose.
        desired_pose: NumPy array with shape ``(4, 4)`` containing the target
            tool pose in the same reference frame.
        step_size: Nonnegative scalar multiplier for each joint update.
        max_iterations: Nonnegative integer limiting the number of updates.
        tolerance: Positive scalar threshold for the norm of the spatial
            error twist. Assume relative rotation angles are less than pi.

    Returns:
        ``(theta, history)``, where theta is a NumPy array with shape ``(N,)``
        and history has shape ``(M, N)``. Include the initial joint values
        and every update, so ``1 <= M <= max_iterations + 1`` and
        ``theta == history[-1]``. Return the latest values even if the target
        is not reached. 
    """

    # TODO

    theta_j = theta.copy()
    history = [theta_j.copy()]

    error = spatial_error_twist(
        spatial_configuration_error(
            forward_kinematics(twists, theta_j) @ g_st0,
            desired_pose
        )
    )

    i = 0

    while np.linalg.norm(error) > tolerance and i < max_iterations:
        J_s = spatial_jacobian(twists, theta_j)

        delta_theta = step_size * np.linalg.pinv(J_s) @ error

        theta_j = theta_j + delta_theta
        history.append(theta_j.copy())
        i += 1

        error = spatial_error_twist(
            spatial_configuration_error(
                forward_kinematics(twists, theta_j) @ g_st0,
                desired_pose
            )
        )

    return theta_j, np.array(history)