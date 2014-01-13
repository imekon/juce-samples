/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_36239125_INCLUDED
#define BINARYDATA_H_36239125_INCLUDED

namespace BinaryData
{
    extern const char*   about_png;
    const int            about_pngSize = 338;

    extern const char*   copy_png;
    const int            copy_pngSize = 265;

    extern const char*   cut_png;
    const int            cut_pngSize = 367;

    extern const char*   paste_png;
    const int            paste_pngSize = 319;

    extern const char*   new_png;
    const int            new_pngSize = 303;

    extern const char*   open_png;
    const int            open_pngSize = 269;

    extern const char*   save_png;
    const int            save_pngSize = 281;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    extern const int namedResourceListSize;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
