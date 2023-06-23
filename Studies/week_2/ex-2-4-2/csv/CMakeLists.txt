add_library(Csv INTERFACE)

target_sources(Csv INTERFACE csv.h)
target_include_directories(Csv INTERFACE ../csv/csv.h)