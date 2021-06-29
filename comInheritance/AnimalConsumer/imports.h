#pragma once

#ifdef _WIN64
#   ifdef _DEBUG
#       import "../AnimalProducer/x64/Debug/AnimalProducer.tlb"
#   else
#       import "../AnimalProducer/x64/Release/AnimalProducer.tlb"
#   endif
#else
#   ifdef _DEBUG
#       import "../AnimalProducer/Debug/AnimalProducer.tlb"
#   else
#       import "../AnimalProducer/Release/AnimalProducer.tlb"
#   endif
#endif
