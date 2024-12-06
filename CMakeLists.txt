cmake_minimum_required(VERSION 3.5)
project(HelloWorld
		VERSION 1.0.0
		DESCRIPTION "goodbye world"
		LANGUAGES CXX)
add_executable(HelloWorldBinary source/main.cpp)
target_compile_features(HelloWorldBinary PRIVATE cxx_std_20)