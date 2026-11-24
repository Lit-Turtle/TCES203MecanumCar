#ifndef CAMERA_H
#define CAMERA_H

class Camera {
private:
    bool streaming;

public:
    Camera();
    void startStreaming();
    void stopStreaming();
    bool isStreaming() const;
    void captureFrame(double x, double y) const;
};

#endif