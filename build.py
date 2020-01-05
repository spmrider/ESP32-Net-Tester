# build.py
# pre-build script, setting up build environment and fetch hal file for user's board

import sys
import os
import os.path
import requests
from os.path import basename
from platformio import util
from SCons.Script import DefaultEnvironment

try:
    import configparser
except ImportError:
    import ConfigParser as configparser

# get platformio environment variables
env = DefaultEnvironment()
config = configparser.ConfigParser()
config.read("platformio.ini")

# get platformio source path
srcdir = env.get("PROJECTSRC_DIR")

# check if net config file is present in source directory
netconffile = os.path.join (srcdir, config.get("common", "netconffile"))
if os.path.isfile(netconffile) and os.access(netconffile, os.R_OK):
    print("Parsing network config from " + netconffile)
else:
    sys.exit("Missing file " + netconffile + ", please create it! Aborting.")
