#!/usr/bin/env wolframscript
(* ::Package:: *)

#!/usr/bin/env wolframscript
argv = Rest @ $ScriptCommandLine;
argc = Length @ argv;

(* Get the file names, set default if user did not specify *)
If[argc>=2,
    queryFileName = argv[[1]];
    errorFileName= argv[[2]],
    queryFileName = "queries.txt";
    errorFileName= "errors.txt"
]

(* Get the file line count *)
null[_String] := Null
queryLength = Length @ ReadList[queryFileName, null @ String, NullRecords -> True]

(* Record for each interval type, how many wrong queries they have *)
errorQueryCount = Association[{}];

(* Load the file *)
queryFile = OpenRead[queryFileName];
errorFile= OpenWrite[errorFileName];


equery[x_] := 
    If[Length[StringSplit[x, ": "]] > 1,
        If[ToExpression[StringTrim[StringSplit[ x, ": "][[2]]], TraditionalForm],
            Return[True],
            (* put this info inside the association *)
            errorCount = Lookup[errorQueryCount, StringSplit[ x, ": "][[1]], 0];
            AssociateTo[errorQueryCount, StringSplit[ x, ": "][[1]] -> errorCount+1];
            Return[False]
        ],
        Return[True]
    ];
checkQuery[line_,outputFile_]:=
    Module[{queryResult},
        queryResult=equery[line];
        If[!queryResult,
            WriteLine[outputFile,line]
        ];
    ]
For[i=1, i<=queryLength, i++, 
    If[Mod[i, queryLength/10]==0,
        message = ToString[StringForm["Queries finished `1`/`2`", i, queryLength]];
        Print[message]
    ];
    line = ReadLine[queryFile];
    checkQuery[line, errorFile];
]
Close[queryFile];
Close[errorFile];

(* Now we want to see how many wrong queries each method has *)
queryKeys = Keys[errorQueryCount];
Do[Print[ToString[StringForm["`1` has `2` wrong queries", queryKeys[[i]], errorQueryCount[queryKeys[[i]]]]]], {i, Length[queryKeys]}]


