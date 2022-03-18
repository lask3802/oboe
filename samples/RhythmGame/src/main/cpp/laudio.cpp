//
// Created by lask3 on 2022/3/18.
//

#include "utils/logging.h"
#include "GameConstants.h"
#include "AudioManager.h"
#include <cstdint>
extern "C"
{
    void Initialize(){

    }

    void Shutdown(){

    }

    void* CreateAudioDataSource(float* data, int64_t length, AudioProperties* audioProperties){

    }



void clog(){
    LOGD("clog is called");
}
}