#include <iostream>
#include <vector>
#include <algorithm>

class AudioDSPFilter {
public:
    static void applyGain(std::vector<float>& buffer, float gainFactor) {
        for (float& sample : buffer) {
            sample *= gainFactor;
            sample = std::clamp(sample, -1.0f, 1.0f);
        }
    }
};

int main() {
    std::vector<float> sampleBuffer = {0.1f, -0.5f, 0.8f, -0.2f};
    AudioDSPFilter::applyGain(sampleBuffer, 1.2f);
    std::cout << "DSP Filter engine initialized and processed chunks successfully.\n";
    return 0;
}
