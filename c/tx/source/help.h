"tx Help\n"
"=======\n"
"[Note: brief usage is available with -u (usage) option.]\n"
"\n"
"tx (Type eXchange) is a test harness for the CoreType libraries but also\n"
"provides many useful font conversion and analysis facilities. These facilities\n"
"are built around the Abstract Font Format (ABF) which is used to exchange font\n"
"data between the various library components. Further details of ABF may be\n"
"found in afdko/c/public/lib/api/absfont.h.\n"
"\n"
"Input\n"
"-----\n",
"Font data is read from input, converted to ABF, which is then converted for\n"
"output. On input, the font technology type and format is automatically detected\n"
"by analyzing the first few bytes of input data. The appropriate library\n"
"component and input filter are then selected to perform the conversion to ABF.\n"
"The output conversion is performed by another library component that is\n"
"selected by a program mode option. A full list of options, including those for\n",
"selecting program modes, is available via the -u option.\n"
"\n"
"Input conversion of the following font technologies is supported: Type 1 single\n"
"master, Type 1 multiple master, Type 1 CID-keyed, CFF single master, CFF\n"
"CID-keyed, and TrueType. Conversion of font data represented in the following\n"
"formats is supported: PFA, PFB, LWFN-POST, FFIL-sfnt, OTF, TTF, TTC, and\n"
"AppleSingle/Double-sfnt. sfnt-formatted fonts with header versions of the\n",
"following kinds are supported: 1.0, true, ttcf, typ1, CID, and OTTO. Note that\n"
"OCF is not supported by tx.\n"
"\n"
"Multiple master fonts are always snapshot during input conversion. The snapshot\n"
"instance may be specified as a user design vector with -U (user design vector)\n"
"option, e.g -U 365,500. If the -U option is not specified the default instance\n"
"recorded within the font is used.\n"
"\n"
"If the input font is an FFIL or a TTC containing multiple sfnts, a contents\n",
"list is displayed from which a specific sfnt may be selected using the -i\n"
"(index) option or every font may be selected using the -y (every) option in a\n"
"subsequent run of tx. The resource map of an FFIL may also be viewed with the\n"
"-r (resource) option or the entry descriptors in an AppleSingle/Double format\n"
"file may be viewed with the -R option.\n"
"\n"
"By default, curve segments in TrueType glyph paths are converted from quadratic\n"
"to cubic Beziers using an optimization algorithm that coalesces adjacent curve\n",
"segments. However, an exact conversion may be specified with the -x (exact)\n"
"option. Also, the optimized and exact paths may be generated simultaneously for\n"
"comparison purposes with the -X (exact and optimized) option.\n"
"\n"
"The parsing of Type 1 fonts, which are PostScript based and often encrypted,\n"
"can present the greatest challenges when the font is malformed. The -t (tokens)\n"
"option addresses this problem by dumping the PostScript token stream to\n",
"standard output as the font is parsed. The point of failure generally occurs\n"
"shortly after the last dumped token.\n"
"\n"
"The Type 1 PostScript download formats generated by xcf and CoolType are also\n"
"supported. Generally, the download font will have to be excised from the\n"
"PostScript file using a text editor before it can be submitted to tx and\n"
"incremental portions of the font, occurring later in the file, will have to be\n"
"pasted back into the charstrings of the initial font. Also, be sure to add a\n",
"initial line of \"%!\", if one is not already present, to ensure that tx detects\n"
"the format correctly and selects the appropriate input library.\n"
"\n"
"Subsetting\n"
"----------\n"
"An important aspect of tx is its ability to subset fonts by specifying a glyph\n"
"subset with the -g (glyphs) option. The argument to this option consists of a\n"
"comma-separated list of glyph identifiers which may be either a tag, glyph\n"
"name, or CID.\n"
"\n"
"A tag specifies the glyph in a technology-specific way. The tag is incremented\n",
"for each glyph processed, starting from zero. Thus, the last glyph processed is\n"
"assigned a tag value that is one less than the number of glyphs in the font.\n"
"For sfnt-based fonts that tag is the same as the glyph index. For a naked-CID\n"
"font it is derived by counting non-empty intervals in the CIDMap, starting from\n"
"CID 0. For a Type 1 font it is the order number of the charstring in the\n"
"CharStrings dictionary, starting from 0.\n"
"\n",
"Glyph names may be used with non-CID fonts, including TrueType fonts. CIDs may\n"
"only be used with CID-keyed fonts. A tag is specified as a positive integer,\n"
"e.g. 17. A CID is specified by a positive integer preceded by a / (slash)\n"
"character, e.g. /17. A glyph name is specified by a sequence of characters,\n"
"e.g. zero. Tags and CIDs may also be specified as a range by separating the\n"
"smallest and largest members of the range by a - (hyphen), e.g. 34-59.\n"
"\n",
"(Note: the type tools convention for printing a CID is to precede it with a \\\n"
"(backslash) character. However, / is used with the -g option because \\ has a\n"
"special interpretation in most command shells.)\n"
"\n"
"A CID-keyed font may also be subset by font dictionary with the -fd (font dict)\n"
"option. This option takes a single positive integer argument which specifies\n"
"the zero-based index of the font dictionary. Only glyphs that are rendered with\n",
"this dictionary are selected from the input font. It is considered a fatal\n"
"error to use this option with non-CID fonts or to specify an index that is\n"
"outside the range supported by the font.\n"
"\n"
"A random subset can be generated by the -p or -P (percent) options. These\n"
"options take a single argument that specifies the subset size as a percentage\n"
"of the number of glyphs in the source font, and is thus a real value in the\n"
"range 0-100. If this calculation yields an empty subset the subset will be\n",
"forced to contain one glyph. The -p option produces repeatably random subsets\n"
"for a given source font whereas the -P option produces different random subsets\n"
"for each run.\n"
"\n"
"The command line is conventionally specified by input options (described\n"
"above), followed by mode options (described by the -u (usage) option), and\n"
"finally by file options (which must be last). Each mode has its own options\n"
"which must follow the mode selection option. Mode-specific help is available by\n",
"specifying the -h (help) option after the mode selection option.\n"
"\n"
"File options\n"
"------------\n"
"The file options provide a very flexible and powerful way of processing\n"
"multiple input and output files which are described briefly by the -u option.\n"
"Some of the file options are described more fully here.\n"
"\n"
"The source font path is constructed by concatenating root, directory, and\n"
"filename components. The root and directory components are empty by default,\n",
"but may be specified with the -sr (source root) and -sd (source directory)\n"
"options, respectively. This allows some economy in specifying file paths and\n"
"becomes especially important when used in conjunction with the -s (script)\n"
"option, described below.\n"
"\n"
"The destination font path is constructed by concatenating directory and\n"
"filename components. The directory component is empty by default, but may be\n"
"specified with the -dd (destination directory) option. Note: tx will not create\n",
"directories so you must ensure that the destination directory exists before\n"
"running tx.\n"
"\n"
"The -a (automatic) option takes one or more filename arguments. Each argument\n"
"is processed in turn and a source filename is constructed from the root,\n"
"directory, and filename components. The destination filename is constructed by\n"
"concatenating the destination directory component with the source filename less\n"
"its extension, if any, and a . (period) followed by the mode name. For example,\n"
"on Unix the command:\n"
"\n",
"    tx -cff -dd /tmp/cff -a *.pfb\n"
"\n"
"will convert all the .pfb files in the current directory into correspondingly\n"
"named .cff files in the directory /tmp/cff.\n"
"\n"
"The -A option is similar to the -a option except that the destination filename\n"
"is assembled from the FontName of the source font and a . (period) followed by\n"
"the mode name.\n"
"\n"
"Scripting\n"
"---------\n"
"The -s (script) option provides a way of specifying commonly used options and\n"
"filenames in a text file. The file is parsed into a sequence of whitespace-\n",
"delimited arguments which are then presented to tx as though they came from the\n"
"command line. Newlines are treated as whitespace and can be used to improve the\n"
"readability of the script file. If an argument must contain one or more spaces\n"
"it may be enclosed by a pair of \" (double quote) characters. Comments, which\n"
"are ignored by the parser, may be introduced into the file by the # (hash)\n"
"character and extend to the end of the current line. Script files are not\n",
"recursive and therefore cannot include the -s option. The -s option must be the\n"
"last option given on the command line.\n"
"\n"
"The following shows the beginning of a script file that specifies pfb versions\n"
"of the testset fonts on the the Unix server quad.\n"
"\n"
"--- filename: disks-testset-pfb -----------\n"
"# PFB test fonts\n"
"\n"
"-sr /disks/quad/u020/vol1/pc/shipping\n"
"\n"
"# Serif Text Family\n"
"-sd 351-400/352\n"
"rdr_____.pfb    # BernhardModern-Roman\n"
"rdb_____.pfb    # BernhardModern-Bold\n"
"rdi_____.pfb    # BernhardModern-Italic\n",
"rdbi____.pfb    # BernhardModern-BoldItalic\n"
"\n"
"# Sans Text Family\n"
"-sd 351-400/357\n"
"owbk____.pfb    # OfficinaSans-Book\n"
"owb_____.pfb    # OfficinaSans-Bold\n"
"owwi____.pfb    # OfficinaSans-BookItalic\n"
"owbi____.pfb    # OfficinaSans-BoldItalic\n"
"...\n"
"-------------------------------------------\n"
"\n"
"Script files are a good way to specify a large number of source fonts, e.g. all\n"
"those on the Font Folio CD, using -sr, -sd, and filename arguments. These fonts\n",
"can then be processed according to the mode option specified on the command\n"
"line before the -s option. For example, the above script file can be used to\n"
"dump the testset fonts to a PostScript printer with the following command line:\n"
"\n"
"    tx -ps -f -s disks-testset-pfb\n"
"\n"
"Miscellaneous\n"
"-------------\n"
"The -v (version) option shows the versions of all the library components\n"
"linked into tx.\n"
"\n"
"The -m (memory) option simulates a memory allocation failure. First, the -m\n",
"option with an argument of 0, should be added to the tx configuration under\n"
"examination. This will report the total number of memory allocations for that\n"
"configuration (call this M). tx should then be run again but this time using M\n"
"as the argument to the -m option rather than 0. This will cause a failure of\n"
"the memory allocator in one of the first M calls, selected randomly. The\n"
"failing call will be reported (call this N). If it is desired to repeat the\n",
"same failure, tx should be run again but this time with -N (a hyphen followed\n"
"by N) as the argument to the -m option.\n"