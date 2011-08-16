import FWCore.ParameterSet.Config as cms

pixelVTXMonitor = cms.EDAnalyzer("PixelVTXMonitor",
    ModuleName          = cms.string('HLT'),
    FolderName          = cms.string('PixelVertex'),
    PixelVertexInputTag = cms.InputTag('pixelVertices'),
    HLTInputTag         = cms.InputTag('TriggerResults','','HLT'),
    MinVtxDoF           = cms.double(4.0),
#    HLTPathsOfInterest = cms.vstring('HLT_JetE30_NoBPTX_NoHalo_v8', 'HLT_JetE30_NoBPTX_v6', 'HLT_JetE50_NoBPTX3BX_NoHalo_v3', 'HLT_Physics_v2', 'HLT_PixelTracks_Multiplicity100_v6', 'HLT_PixelTracks_Multiplicity80_v6', 'HLT_ZeroBias_v4')
    HLTPathsOfInterest = cms.vstring('HLT_60Jet10', 'HLT_70Jet10','HLT_70Jet13', 'HLT_ZeroBias','HLT_Physics_v')
)
