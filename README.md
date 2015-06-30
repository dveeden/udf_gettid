Description
===========
An MySQL UDF to get the thread id on Linux. This is useful to move MySQL threads/connections to a Linux cgroup.

Installation
============

    $ gcc -o udf_gettid.so udf_gettid.c `mysql_config --include` -shared -fPIC

    mysql> CREATE FUNCTION gettid RETURNS INTEGER SONAME 'udf_gettid.so';

Example
=======

    mysql> SELECT gettid();
    +----------+
    | gettid() |
    +----------+
    |     8877 |
    +----------+
