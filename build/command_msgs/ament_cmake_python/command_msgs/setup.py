from setuptools import find_packages
from setuptools import setup

setup(
    name='command_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('command_msgs', 'command_msgs.*')),
)
