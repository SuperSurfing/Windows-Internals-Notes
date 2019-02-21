#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# ref https://www.jb51.net/article/82562.htm

import os
import shutil


def scandir(startdir, target):
    os.chdir(startdir)
    for obj in os.listdir(os.curdir):
        if obj == target:
            print(os.getcwd() + os.sep + obj)
            if os.path.isdir(obj):
                shutil.rmtree(os.getcwd() + os.sep + obj)  # 删除此文件夹
            else :
                os.remove(os.getcwd() + os.sep + obj)
        if os.path.isdir(obj):
            scandir(obj, target)
            os.chdir(os.pardir)


startdir = input('Please input startdir: ')
target = input('Please input target: ')
scandir(startdir, target)