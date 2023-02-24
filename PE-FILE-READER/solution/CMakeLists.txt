file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(section-extractor ${sources} include/portable.h src/pe_reader.c include/printer.h include/mainPage.h)
target_include_directories(section-extractor PRIVATE src include)
