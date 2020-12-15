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

The original ask was to take an XML file with a "catalog of CDs" and convert it to an HTML file. Upon inspecting the sample XML file, my first thought was "oh, the real problem here is parse in a series of data, and output it in another format". As the original ask was to convert an XML file to an HTML table I've only included that functionality. However, considerations were made to exend the code in the future. XML could be JSON one day, and HTML tables could become CSV files.

In the event that other formats need be supported, a strategy or factory pattern could be employed. I've noted in source code comments where I think each pattern may be appropriate. The data shouldn't care about its format, nor should the user of the data. This was the mentality I had when writing the `KeyValueData` class. Please refer to the source code header files for more comments.

Another ask of the exercise was to demonstrate "engineering best practices". On that note, I've included a few error handling cases, test cases as well as some basic logging. Again in the context of an actual project there would certainly be more unit tests; I've only included a few as an example. There should be a [pull request](https://github.com/justin-is-afk/ot_technical_exercise/pull/1/files) open to modify `main` to run the unit tests. Here's the output you can expect, if you re-build the code with that branch and run the tests:

<details><summary>Example Gtest output</sample>

```
~/dev/ot_technical_exercise$ ./xml2html 
2020-12-15 16:18:15.375 (   0.000s) [        1DEC2740]               main.cpp:10    INFO| Begin XML to HTML Table testing...
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from XML2HTML
[ RUN      ] XML2HTML.valid_xml_file
2020-12-15 16:18:15.375 (   0.000s) [        1DEC2740]          xml_parse.cpp:41    INFO| XML "data/cd_catalog.xml" parsed without errors, reading <CATALOG>
2020-12-15 16:18:15.375 (   0.001s) [        1DEC2740]          xml_parse.cpp:63    INFO| <CATALOG> data imported from "data/cd_catalog.xml"
2020-12-15 16:18:15.376 (   0.001s) [        1DEC2740]html_table_generate.cpp:25    INFO| Generating HTML Table "data/cd_catalog.html"
2020-12-15 16:18:15.377 (   0.003s) [        1DEC2740]html_table_generate.cpp:57    INFO| Successfully generated <CATALOG> table "data/cd_catalog.html"
[       OK ] XML2HTML.valid_xml_file (2 ms)
[ RUN      ] XML2HTML.malformed_xml
2020-12-15 16:18:15.378 (   0.003s) [        1DEC2740]          xml_parse.cpp:22     ERR| "data/cd_catalog_malformed.xml" Invalid or malformed input data
[       OK ] XML2HTML.malformed_xml (1 ms)
[ RUN      ] XML2HTML.empty_xml
2020-12-15 16:18:15.378 (   0.003s) [        1DEC2740]          xml_parse.cpp:22     ERR| "data/cd_catalog_empty.xml" Invalid or malformed input data
[       OK ] XML2HTML.empty_xml (0 ms)
[ RUN      ] XML2HTML.vehicle_data
2020-12-15 16:18:15.378 (   0.003s) [        1DEC2740]          xml_parse.cpp:41    INFO| XML "data/vehicle_data.xml" parsed without errors, reading <VEHICLES>
2020-12-15 16:18:15.378 (   0.003s) [        1DEC2740]          xml_parse.cpp:63    INFO| <VEHICLES> data imported from "data/vehicle_data.xml"
2020-12-15 16:18:15.378 (   0.003s) [        1DEC2740]html_table_generate.cpp:25    INFO| Generating HTML Table "data/vehicle_data.html"
2020-12-15 16:18:15.378 (   0.004s) [        1DEC2740]html_table_generate.cpp:57    INFO| Successfully generated <VEHICLES> table "data/vehicle_data.html"
[       OK ] XML2HTML.vehicle_data (0 ms)
[----------] 4 tests from XML2HTML (3 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (4 ms total)
[  PASSED  ] 4 tests.
```

</details>

Regarding my choice of libraries, I'll start with the XML parser. Parsing XML is a solved problem, and as I've stated above I don't think it's the core issue at hand for this exercise. Logging is also a solved problem, so again I've opted to use a library. For the unit tests, I've had good experiences with gtest in the past. Were I writing this code for a real project though, I'm sure I would be using the logging and testing libraries already in place at the organization. I'd also like to note that while the logging I've implemented goes to the console (for simplicity / convenience), I expect it would be done to a file in the context of a project for an organization with existing code and test infrastructure.

I would love to hear your feedback. I can be reached via email at jlgodson.eng@gmail.com or via cell at `416-828-5336`. Thanks for taking a look!
