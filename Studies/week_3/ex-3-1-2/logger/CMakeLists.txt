add_library(Logger INTERFACE)

target_sources(Logger INTERFACE logger.h)
target_include_directories(Logger INTERFACE ../header/header.h)