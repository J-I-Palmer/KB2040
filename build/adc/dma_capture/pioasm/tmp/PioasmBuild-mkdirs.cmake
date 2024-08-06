# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/vboxuser/pico/pico-sdk/tools/pioasm"
  "/home/vboxuser/pico/pico-examples/build/pioasm"
  "/home/vboxuser/pico/pico-examples/build/adc/dma_capture/pioasm"
  "/home/vboxuser/pico/pico-examples/build/adc/dma_capture/pioasm/tmp"
  "/home/vboxuser/pico/pico-examples/build/adc/dma_capture/pioasm/src/PioasmBuild-stamp"
  "/home/vboxuser/pico/pico-examples/build/adc/dma_capture/pioasm/src"
  "/home/vboxuser/pico/pico-examples/build/adc/dma_capture/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/vboxuser/pico/pico-examples/build/adc/dma_capture/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/vboxuser/pico/pico-examples/build/adc/dma_capture/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
