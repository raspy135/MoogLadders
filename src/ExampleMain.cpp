#pragma comment(user, "license")

#if defined(_MSC_VER)
#pragma comment(lib, "dsound.lib")
#endif

#include "AudioDevice.h"
#include "NoiseGenerator.h"

#include <thread>
#include <chrono>
#include <vector>

int main()
{
    AudioDevice::ListAudioDevices();
    
    int desiredSampleRate = 44100;
    AudioDevice device(2, desiredSampleRate);
    device.Open(device.info.id);
    
    NoiseGenerator gen;
    
    std::vector<float> noiseSamples = gen.produce(NoiseGenerator::NoiseType::WHITE, desiredSampleRate, 2, 5.0);
    
    device.Play(noiseSamples);
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    return 0;
}