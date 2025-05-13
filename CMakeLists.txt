cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(AP_DHCP C CXX)
set(PICO_CYW43_SUPPORTED_COUNTRY_CODES "GB")

pico_sdk_init()

add_executable(AP_DHCP
        main.cpp
        dhcpserver/dhcpserver.cpp
        serverlogic/serverlogic.cpp
        )

target_include_directories(AP_DHCP PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts
        ${CMAKE_CURRENT_LIST_DIR}/dhcpserver
        ${CMAKE_CURRENT_LIST_DIR}/serverlogic
        )

target_link_libraries(AP_DHCP
        pico_cyw43_arch_lwip_threadsafe_background
        pico_stdlib
        )
target_include_directories(AP_DHCP PRIVATE ${PICO_SDK_PATH}/lib/cyw43-driver/src)

pico_enable_stdio_usb(AP_DHCP 1)
pico_enable_stdio_uart(AP_DHCP 0)

pico_configure_ip4_address(AP_DHCP PRIVATE
        CYW43_DEFAULT_IP_AP_ADDRESS 192.168.4.1
        )
pico_add_extra_outputs(AP_DHCP)
