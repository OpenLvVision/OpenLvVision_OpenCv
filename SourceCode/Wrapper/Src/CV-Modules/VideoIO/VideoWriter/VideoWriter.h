#pragma once

#include "opencv2/videoio.hpp"
#include "../../../Interorp/Edvr/EdvrTypes.h"
#include "../../../Interorp/MatHandling/Mathandling.h"
#include "../../../Interorp/ErrorHandling/ErrorHandling.h"
#include "../../../Interorp/ArrayHandling/Array1D.hpp"
#include "../../../Interorp/StringHandling/StringHandling.h"
#include "../../../Interorp/Points.hpp"

extern "C"
{

#pragma region Create / Open

    _declspec(dllexport) void CV_VIDEOIO_WRITER_Create(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef);

    _declspec(dllexport) void CV_VIDEOIO_WRITER_Open(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        const char* filename, int32_t fourcc, double fps,
        lvi::point::PointI32* frameSize, LVBoolean* isColor,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_WRITER_OpenWithBackend(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        const char* filename, int32_t apiPreference,
        int32_t fourcc, double fps,
        lvi::point::PointI32* frameSize, LVBoolean* isColor,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_WRITER_OpenWithParams(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        const char* filename, int32_t fourcc, double fps,
        lvi::point::PointI32* frameSize,
        lvi::array::LV_1DArrayHandle<int32_t> paramsHandle,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_WRITER_OpenWithBackendAndParams(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        const char* filename, int32_t apiPreference,
        int32_t fourcc, double fps,
        lvi::point::PointI32* frameSize,
        lvi::array::LV_1DArrayHandle<int32_t> paramsHandle,
        LVBoolean* result);

#pragma endregion Create / Open

#pragma region Write

    _declspec(dllexport) void CV_VIDEOIO_WRITER_Write(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc);

#pragma endregion Write

#pragma region Properties

    _declspec(dllexport) void CV_VIDEOIO_WRITER_Get(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        int32_t propId,
        double* value);

    _declspec(dllexport) void CV_VIDEOIO_WRITER_Set(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        int32_t propId, double value,
        LVBoolean* result);

#pragma endregion Properties

#pragma region Info

    _declspec(dllexport) void CV_VIDEOIO_WRITER_IsOpened(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_WRITER_GetBackendName(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        LStrHandle resultHandle);

    _declspec(dllexport) void CV_VIDEOIO_WRITER_Release(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef);

#pragma endregion Info

}
