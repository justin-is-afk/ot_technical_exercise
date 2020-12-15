# ot_technical_exercise

### Environment and running the executable

This project was developed on Ubuntu 18.04.5 LTS.

To get the files, download them as zip or run `git clone git@github.com:justin-is-afk/ot_technical_exercise.git`. You can run the executable `xml2html` directly via the command line as below:

```
~/dev/ot_technical_exercise$ ./xml2html data/cd_catalog.xml 
2020-12-15 14:54:05.264 (   0.000s) [        C0634740]               main.cpp:12    INFO| Begin XML to HTML Table conversion of "data/cd_catalog.xml"
2020-12-15 14:54:05.264 (   0.000s) [        C0634740]          xml_parse.cpp:25    INFO| XML "data/cd_catalog.xml" parsed without errors, reading <CATALOG>
2020-12-15 14:54:05.265 (   0.000s) [        C0634740]          xml_parse.cpp:47    INFO| <CATALOG> data imported from "data/cd_catalog.xml"
2020-12-15 14:54:05.265 (   0.000s) [        C0634740]html_table_generate.cpp:21    INFO| Generating HTML Table "data/cd_catalog.html"
2020-12-15 14:54:05.265 (   0.000s) [        C0634740]html_table_generate.cpp:53    INFO| Successfully generated <CATALOG> table "data/cd_catalog.html"

```

By default, the executable will parse the file (provided it exsits) and look for a `<CATALOG>`, with `<CD>` entries. If a valid XML file is given with different data (For exmaple, refer to `data/vehicle_data.xml`) then you should see:

```
~/dev/ot_technical_exercise$ ./xml2html data/vehicle_data.xml 
2020-12-15 14:54:09.566 (   0.000s) [        2D93C740]               main.cpp:12    INFO| Begin XML to HTML Table conversion of "data/vehicle_data.xml"
2020-12-15 14:54:09.566 (   0.000s) [        2D93C740]          xml_parse.cpp:21     ERR| Node <CATALOG> does not exist in "data/vehicle_data.xml"
```

The generated HTML table can be found at `data/table.html`. Note that the code can be modified for parsing different types of data (please refer to the example `data/vehicle_data.xml`):

```
~/dev/ot_technical_exercise$ ./xml2html data/vehicle_data.xml 
2020-12-15 14:55:51.645 (   0.000s) [        3824A740]               main.cpp:12    INFO| Begin XML to HTML Table conversion of "data/vehicle_data.xml"
2020-12-15 14:55:51.645 (   0.000s) [        3824A740]          xml_parse.cpp:25    INFO| XML "data/vehicle_data.xml" parsed without errors, reading <VEHICLES>
2020-12-15 14:55:51.645 (   0.000s) [        3824A740]          xml_parse.cpp:47    INFO| <VEHICLES> data imported from "data/vehicle_data.xml"
2020-12-15 14:55:51.645 (   0.000s) [        3824A740]html_table_generate.cpp:21    INFO| Generating HTML Table "data/table.html"
2020-12-15 14:55:51.645 (   0.000s) [        3824A740]html_table_generate.cpp:53    INFO| Successfully generated <VEHICLES> table "data/table.html"
```

As the exercise description called for an executable that would take in a filename, the pre-built executable `xml2html` included takes in only such. This could easily be modified to additionally take in the XML node name that should be parsed, for example `<CATALOG>` for `data/cd_catalog.xml` or `<VEHICLES` for `data/vehicle_data.xml`, as well as the output file name (`data/table.html`).

### Building from source

In order to build from source, `build-essential` and `libgtest-dev` are required. You can install them manually, or use the provided `setup.sh`. It works on my computer... and hopefully it will work on yours too! If not, feel free to email me at jlgodson.eng@gmail.com. 

To build the code, simply run:

```
cmake CMakeLists.txt
make
```

You can then run `xml2hml` from the command line. Alternatively, you can run `. buildAndRun.sh` which will invoke the above commands, and then run `./xml2html data/cd_catalog.xml` using the default `cd_catalog.xml`.

### Libraries used

- [PugiXML](https://github.com/zeux/pugixml), "Light-weight, simple and fast XML parser for C++ with XPath support"
- [Loguru](https://github.com/emilk/loguru), "A lightweight C++ logging library"
- [Googletest](https://github.com/google/googletest), "Googletest - Google Testing and Mocking Framework"

### Approach and thought process

todo.