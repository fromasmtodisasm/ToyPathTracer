
#if defined(__APPLE__) && !defined(__METAL_VERSION__) && !defined(ISPC)
#include <TargetConditionals.h>
#endif

#define kBackbufferWidth 1280
#define kBackbufferHeight 720

#if defined(__EMSCRIPTEN__)
#define CPU_CAN_DO_SIMD 0
#define CPU_CAN_DO_THREADS 0
#else
#define CPU_CAN_DO_SIMD 1
#define CPU_CAN_DO_THREADS 1
#endif


#define DO_SAMPLES_PER_PIXEL 4
#define DO_ANIMATE_SMOOTHING 0.9f
#define DO_LIGHT_SAMPLING 1
#define DO_MITSUBA_COMPARE 0
#define DO_DEBUG_NORMALS 0
#define DO_VERY_SIMPLE 0

// Should CPU path tracing be done via ISPC?
#define DO_ISPC 1

// Should path tracing be done on the GPU with a compute shader?
#define DO_COMPUTE_GPU 0
#define kCSGroupSizeX 8
#define kCSGroupSizeY 8
#define kCSMaxObjects 64

// Should float3 struct use SSE/NEON?
#define DO_FLOAT3_WITH_SIMD (!(DO_COMPUTE_GPU) && !(DO_ISPC) && CPU_CAN_DO_SIMD && 1)

// Should HitSpheres function use SSE/NEON?
#define DO_HIT_SPHERES_SIMD (CPU_CAN_DO_SIMD && 1)
