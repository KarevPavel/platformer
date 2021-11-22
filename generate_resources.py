#!/usr/bin/env python3
import argparse
import os
import sys
import pathlib
import platform
from typing import List

def write_lines(filename, lines):
    with open(filename, 'w') as f:
        for l in lines:
            f.write(l + '\n')

def read_interface_names(path):
    dictionary = dict()
    for subdir, dirs, files in os.walk(path):
        for file in files:
            headerName = ''.join(name for idx, name in enumerate(subdir[subdir.rindex('/') + 1:len(subdir)]))
            if headerName != "" and headerName != "/resources":
                filepath = subdir + '/' + file
                if os.path.isfile(filepath):
                    resPath = 'resources'
                    ## + 1 это сепаратор / или \
                    filepath = filepath[filepath.rindex(resPath) + 1 + len(resPath):len(filepath)]
                    if platform.system() == 'Windows':
                        headerName = headerName.replace('\\', '/')
                    
                    if dictionary.__contains__(headerName):
                        dictionary[headerName].append(filepath)
                    else:
                        dictionary[headerName] = [filepath]
    return dictionary

def generate_implementation(name):
    lines = ['#include "{}.hpp"'.format(name)]
    write_lines(name + '.cpp', lines)

def generate_header(fileName, constants: List[str]):
    fields = []
    clause = []

    for constant in constants:
        dirtyFileName = str(constant)
        pureConstantName = maskFileName(dirtyFileName)
        fields.append('\tstatic const std::string ' + pureConstantName.upper() + '="' + pureConstantName + '";')
        fields.append('\tstatic const std::string ' + pureConstantName.upper() + '_PATH = "' +
                      str(pathlib.Path().resolve().absolute()) + "/resources/" + dirtyFileName + '";')
        clause.append("\t\tif (inputField == \"" +  pureConstantName.upper()  +"\") {"
                      "\t\t\nreturn " + pureConstantName.upper() + ";"
                      "\t\t\n}")
    function = [
        "static std::string " + fileName[0:len(fileName) - 1] + "ByFieldName(std::string &inputField) {",
        "std::transform(inputField.begin(), inputField.end(), inputField.begin(), ::toupper);",
        ''.join(clause),
        "}"
    ]

    code = ['#pragma once\n',
            '#include <string>\n',
            '#include <algorithm>\n',
            'namespace constants {\n',
            '\n'.join(fields),
            '\n'.join(function),
            '}']

    write_lines(fileName + '.hpp', code)

def maskFileName(dirtyFileName):
    if dirtyFileName.find("/") != -1:
        return dirtyFileName[dirtyFileName.rindex("/") + 1:dirtyFileName.rindex('.')].replace('.','_').replace('-','_').replace(' ', '_')

    return dirtyFileName[0:dirtyFileName.rindex('.')].replace('.','_').replace('-','_').replace(' ', '_')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate some cpp/hpp files.')
    parser.add_argument('inputfile')
    parser.add_argument('--print-dependencies',
                        dest='print_dependencies',
                        action='store_const',
                        default=False,
                        const=True,
                        help='Print file dependencies, do not generate anything')
    args = parser.parse_args()

    headers = read_interface_names(args.inputfile)
    if args.print_dependencies:
        sep = ';'
        print(sep.join(['{0}.hpp{1}{0}.cpp'.format(name, sep) for name in headers.keys()]), end='')
        sys.exit(0)

    for headerName in headers.keys():
        generate_header(headerName, headers[headerName])
        generate_implementation(headerName)

