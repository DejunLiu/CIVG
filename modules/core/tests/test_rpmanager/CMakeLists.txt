# Arynga CarSync(TM)
# 2014-2015 Copyrights by Arynga Inc. All rights reserved.

project(test_rpmanager)
cmake_minimum_required(VERSION 2.8)

if (NOT TARGET test_rpmanager)
    include_directories(../../../rpmanager)
    include_directories(../../../proto)
    include_directories(${GENERATED_FILES_DIR})

    add_library(test_rpmanager STATIC
        test_rpmanager.h
        test_rpmanager.c
    )
    add_dependencies(test_rpmanager proto)
endif()
