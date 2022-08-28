.PHONY: build

build:
	@mkdir -p build
	@g++ main.cpp --std=c++17 -o build/raytrace

run:
	@make build
	@build/raytrace > build/image.ppm

