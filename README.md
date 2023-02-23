This is an example of a C++ client application using MigratoryData Client C++ API.

The latest build of the API can be downloaded from [here](https://migratorydata.com/downloads/migratorydata-6/).

This C++ example application connects to the MigratoryData Server running at `127.0.0.1:8080`, subscribes to the subject `/server/status` and displays the messages received from the MigratoryData server. Also, it publishes messages on the same subject.

You can edit the source code of this example application to connect to your instance of MigratoryData Server and subscribe / publish to your subjects. Then, use the build script `build.bat` to (re)compile the example application. 

If you don't have a MigratoryData server installed on your machine but there is docker installed you can run the following command to start MigratoryData server, otherwise you can download and install the latest version for your os from [here](https://migratorydata.com/downloads/migratorydata-6/).

```bash
docker pull migratorydata/server:latest
docker run -d --name my_migratorydata -p 8800:8800 migratorydata/server:latest
```

#### REQUIREMENTS

- You need to have installed Visual Studio 2019 with C++ development

- You might need to adapt the value of the variable `CC_DIR` of the script `build.bat` to reflect your setup

#### STRUCTURE

The delivery package of this example has the following structure:

 - `lib` is the folder which contains the MigratoryData Client C++ API library.

 - `include` is the folder which contains the headers files of MigratoryData Client C++ API.

 - `build.bat` is the build script which is used to compile this example application on Windows.

 - `main.cpp` is the source code of this example application.
 	                 	                             	   
#### MODIFYING AND (RE)BUILDING THE SOURCE CODE

1. Edit the source code file

2. Run the `build.bat` to rebuild the source code for Windows

3. Run the executable produced at Step 2.
