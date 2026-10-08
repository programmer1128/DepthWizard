#pragma once

#include "NdsmInferenceTypes.h"
#include "SemanticInferenceTypes.h"

// Complete output of the two independent inference branches. Keeping these
// bundles separate prevents nDSM confidence or validity from being mistaken
// for semantic confidence or validity downstream.
struct DualModelInferenceBundle
{
    NdsmInferenceBundle ndsm;
    SemanticInferenceBundle semantics;
};
