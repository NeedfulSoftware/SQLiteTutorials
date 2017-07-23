/*
    Copyright (c) 2017 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include <sqlite3.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    sqlite3* db = NULL;

    int rc = sqlite3_open("MyFirstSQLiteDB.db", &db);
    if (rc != 0)
    {
        printf("Error creating database handle (return code: %d)\n", rc);
    }
    else
    {
        char* sql = "CREATE TABLE PERSONS(FIRSTNAME CHAR PRIMARY KEY NOT NULL);";
        char* errorMessage = 0;
        rc = sqlite3_exec(db, sql, 0, 0, &errorMessage);
        if (rc != 0)
        {
            printf("Error creating table (return code: %d)\n", rc);
            if (errorMessage)
            {
                printf("Error message: %s\n", errorMessage);
            }
        }
        sqlite3_free(errorMessage);
    }

    sqlite3_close(db);

    return 0;
}
