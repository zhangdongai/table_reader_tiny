This program is designed for an assignment.
### The Description of the assignment
'''Given a table with several(indeterminate) columns, each column has its own type which could be one of Int, float, string etc, what's more, users could specify a customized type as a column. 

Read a line from the table each time, and parse all data fields and print out. As to customized type, it should be parsed be calling its own parse function.

Your program should be readable, safe and robust.
'''

## Dependency
boost

`sudo apt-get install libboost-all-dev`

gtest

please refer to [gtest installation](https://github.com/zhangdongai/objectpool/blob/master/objectpool/install_gtest.sh) to install gtest

## How is it
In the author's point of view, this program is implmented with some relatively advanced features in C++, such as `polymorphism` , `template`,`specialization`, `partial specialization`, `__VA_ARGS__` etc. 

It's tiny, easy to read and debug. It's a good material to learn something...
