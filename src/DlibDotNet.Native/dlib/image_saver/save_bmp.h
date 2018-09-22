#ifndef _CPP_SAVE_BMP_H_
#define _CPP_SAVE_BMP_H_

#include "../export.h"
#include <dlib/array2d/array2d_kernel.h>
#include <dlib/image_io.h>
#include <dlib/image_saver/image_saver.h>
#include <dlib/pixel.h>
#include <dlib/image_processing/generic_image.h>
#include "../shared.h"

using namespace dlib;
using namespace std;

#pragma region template

#define save_bmp_matrix_template(ELEMENT) \
do {\
    if (templateRows == 0 && templateColumns == 0)\
    {\
        dlib::matrix<ELEMENT>& mat = *(static_cast<dlib::matrix<ELEMENT>*>(matrix));\
        dlib::save_bmp(mat, file_name);\
    }\
    else if (templateRows == 0 && templateColumns == 1)\
    {\
        dlib::matrix<ELEMENT, 0, 1>& mat = *(static_cast<dlib::matrix<ELEMENT, 0, 1>*>(matrix));\
        dlib::save_bmp(mat, file_name);\
    }\
    else if (templateRows == 1 && templateColumns == 3)\
    {\
        dlib::matrix<ELEMENT, 1, 3>& mat = *(static_cast<dlib::matrix<ELEMENT, 1, 3>*>(matrix));\
        dlib::save_bmp(mat, file_name);\
    }\
    else if (templateRows == 31 && templateColumns == 1)\
    {\
        dlib::matrix<ELEMENT, 31, 1>& mat = *(static_cast<dlib::matrix<ELEMENT, 31, 1>*>(matrix));\
        dlib::save_bmp(mat, file_name);\
    }\
    else\
    {\
        err = ERR_MATRIX_ELEMENT_TEMPLATE_SIZE_NOT_SUPPORT;\
    }\
} while (0)

#pragma endregion template

DLLEXPORT int save_bmp(array2d_type type, void* image, const char* file_name)
{
    int err = ERR_OK;
    switch(type)
    {
        case array2d_type::UInt8:
            dlib::save_bmp(*((array2d<uint8_t>*)image), file_name);
            break;
        case array2d_type::UInt16:
            dlib::save_bmp(*((array2d<uint16_t>*)image), file_name);
            break;
        case array2d_type::UInt32:
            dlib::save_bmp(*((array2d<uint32_t>*)image), file_name);
            break;
        case array2d_type::Int8:
            dlib::save_bmp(*((array2d<int8_t>*)image), file_name);
            break;
        case array2d_type::Int16:
            dlib::save_bmp(*((array2d<int16_t>*)image), file_name);
            break;
        case array2d_type::Int32:
            dlib::save_bmp(*((array2d<int32_t>*)image), file_name);
            break;
        case array2d_type::Float:
            dlib::save_bmp(*((array2d<float>*)image), file_name);
            break;
        case array2d_type::Double:
            dlib::save_bmp(*((array2d<double>*)image), file_name);
            break;
        case array2d_type::RgbPixel:
            dlib::save_bmp(*((array2d<rgb_pixel>*)image), file_name);
            break;
        case array2d_type::HsiPixel:
            dlib::save_bmp(*((array2d<hsi_pixel>*)image), file_name);
            break;
        case array2d_type::RgbAlphaPixel:
            dlib::save_bmp(*((array2d<rgb_alpha_pixel>*)image), file_name);
            break;
        default:
            err = ERR_ARRAY_TYPE_NOT_SUPPORT;
            break;
    }

    return err;
}

DLLEXPORT int save_bmp_matrix(matrix_element_type type, void* matrix, const int templateRows, const int templateColumns, const char* file_name)
{
    int err = ERR_OK;

    switch(type)
    {
        case matrix_element_type::UInt8:
            save_bmp_matrix_template(uint8_t);
            break;
        case matrix_element_type::UInt16:
            save_bmp_matrix_template(uint16_t);
            break;
        case matrix_element_type::UInt32:
            save_bmp_matrix_template(uint32_t);
            break;
        case matrix_element_type::Int8:
            save_bmp_matrix_template(int8_t);
            break;
        case matrix_element_type::Int16:
            save_bmp_matrix_template(int16_t);
            break;
        case matrix_element_type::Int32:
            save_bmp_matrix_template(int32_t);
            break;
        case matrix_element_type::Float:
            save_bmp_matrix_template(float);
            break;
        case matrix_element_type::Double:
            save_bmp_matrix_template(double);
            break;
        case matrix_element_type::RgbPixel:
            save_bmp_matrix_template(rgb_pixel);
            break;
        case matrix_element_type::HsiPixel:
            save_bmp_matrix_template(hsi_pixel);
            break;
        case matrix_element_type::RgbAlphaPixel:
            save_bmp_matrix_template(rgb_alpha_pixel);
            break;
        default:
            err = ERR_ELEMENT_TYPE_NOT_SUPPORT;
            break;
    }

    return err;
}

#endif