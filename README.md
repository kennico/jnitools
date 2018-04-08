# jnitools

## Notes
Manipulating Java arrays and objects(not implemented) in cpp.
- Access java array objects
```
//
// Print integers in an array.
// Argument array is declared of type jintarray
//
ArrayAccess<jintArray> access(env, array);
std::for_each(access.cbegin(), access.cend(), [](auto e) {
    printf("%ld ", e);
});
```

- Create java array objects of native type
```
jchar temp[] = { 'm','i','s','a','k','a','1','0','0','3','2' };
ArrayUtils<jcharArray>(env).createArray(sizeof(temp) / sizeof(jchar), temp);
```
- Create Java objects

```
knylaw::jni::Clazz(/*class name*/, env).instance(env, /*cstring signature*/, /*variadic args*/);
```
- Exceptions


## Demo Configuration

### JAVA

#### `./test/java`
- Change directory to `./test/java/src`
- Run ` javah -d ../../cpp serkenny.jnitools.NativeMethods` to generate the c header for `.java` where native methods reside
- Run any main method with `-Djava.library.path=..\Debug` to tell JVM where to find the `.dll`.

### C++

#### `./jnitools`
Entry|Content
-|-|-
Configuration Type|Static Library `jnitools.lib`
Additional Include Directories|%JAVA_HOME%\include;%JAVA_HOME%\include\win32;%JAVA_HOME%\include\win32\bridge;%(AdditionalIncludeDirectories)

#### `./test/cpp`
Entry|Content
-|-
Configuration Type|Dynamic Library `cpp.dll`
Additional Include Directories|$(SolutionDir)jnitools\src;%JAVA_HOME%\include;%JAVA_HOME%\include\win32;%JAVA_HOME%\include\win32\bridge;%(AdditionalIncludeDirectories)
Additional Library Directories|$(OuputPath)

    

