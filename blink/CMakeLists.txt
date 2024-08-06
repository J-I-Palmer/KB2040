add_executable(blink
	blink.c
)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)

# pull in common dependencies
pico_generate_pio_header(blink ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)
target_link_libraries(blink PRIVATE pico_stdlib hardware_pio)


# create map/bin/hex file etc.
pico_add_extra_outputs(blink)

# add url via pico_set_program_url
example_auto_set_url(blink)
