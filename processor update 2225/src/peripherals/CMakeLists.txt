add_library(Peripherals peripherals.cpp 
                        ADC.cpp 
                        USART.cpp 
                        port.cpp 
                        jtag.cpp 
                        spi.cpp 
                        PWMChannel.cpp 
                        Timer.cpp
            )
target_include_directories(Peripherals PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
