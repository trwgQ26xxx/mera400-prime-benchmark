#!/bin/sh
set -eu

gcc prime.c -o prime -lm -Wno-old-style-definition
