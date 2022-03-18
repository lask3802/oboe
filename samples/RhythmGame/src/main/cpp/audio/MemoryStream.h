//
// Created by lask3 on 2022/3/7.
//

#ifndef SAMPLES_MEMORYSTREAM_H
#define SAMPLES_MEMORYSTREAM_H

#include <memory>
#include <algorithm>
class ReadOnlyMemoryStream{
public:
    virtual size_t read(uint8_t* data, size_t size) = 0;
    virtual int64_t seek(size_t offset) = 0;
    virtual size_t size() const = 0;
};

template<class TBuffer>
class SharedStream: public ReadOnlyMemoryStream{
public:
    SharedStream(TBuffer mBuffer) : mBuffer(mBuffer),
    mSize(mBuffer.size()),
    mOffset(0),
    mCapacity(mBuffer.capacity())
    {}

    size_t read(uint8_t *data, size_t size) override {
        const size_t availableSize = std::min(size, mSize - mOffset - 1);
        memcpy(data, &mBuffer[mOffset], availableSize);
        mOffset+=availableSize;
        return availableSize;
    }

    int64_t seek(size_t offset) override {
        if(offset >= mSize || offset <0) return -1;
        mOffset = offset;
        return offset;
    }

    size_t size() const override {
        return mSize;
    }

private:
    TBuffer mBuffer;
    size_t mSize;
    size_t mOffset;
    size_t mCapacity;
};

class MemoryStream: public ReadOnlyMemoryStream{
public:
    MemoryStream(size_t size):
            mBuffer(std::make_unique<uint8_t[]>(size)),
            mSize(0),
            mOffset(0),
            mCapacity(size)
    {

    }
    size_t write(const uint8_t *data, size_t size) {
        size_t availableSize = std::min(size, mCapacity - mOffset - 1);
        memcpy(&mBuffer.get()[mOffset], data, availableSize);
        mSize+=size;
        mOffset+=size;
        return mOffset;
    }

    size_t read(uint8_t *data, size_t size) override{
        const size_t availableSize = std::min(size, mSize - mOffset - 1);
        memcpy(data, &mBuffer.get()[mOffset], availableSize);
        mOffset+=availableSize;
        return availableSize;
    }

    int64_t seek(size_t offset) override {
        if(offset >= mSize || offset <0) return -1;
        mOffset = offset;
        return offset;
    }

    size_t size() const override {
        return mSize;
    }

private:
    std::unique_ptr<uint8_t[]> mBuffer;
    size_t mSize;
    size_t mOffset;
    size_t mCapacity;
};





#endif //SAMPLES_MEMORYSTREAM_H
