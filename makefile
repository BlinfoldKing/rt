.PHONY: build

build:
	@mkdir -p build
	@g++ main.cpp -o build/raytrace

run:
	@make build
	@build/raytrace > image.ppm

