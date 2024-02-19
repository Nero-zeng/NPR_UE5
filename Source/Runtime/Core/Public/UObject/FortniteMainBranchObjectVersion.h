// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "DevObjectVersion.h"
#include "Containers/Map.h"

// Custom serialization version for changes made in the //Fortnite/Main stream
struct FFortniteMainBranchObjectVersion
{
	enum Type
	{
		// Before any version changes were made
		BeforeCustomVersionWasAdded = 0,

		// World composition tile offset changed from 2d to 3d
		WorldCompositionTile3DOffset,

		// Minor material serialization optimization
		MaterialInstanceSerializeOptimization_ShaderFName,

		// Refactored cull distances to account for HLOD, explicit override and globals in priority
		CullDistanceRefactor_RemovedDefaultDistance,
		CullDistanceRefactor_NeverCullHLODsByDefault,
		CullDistanceRefactor_NeverCullALODActorsByDefault,

		// Support to remove morphtarget generated by bRemapMorphtarget
		SaveGeneratedMorphTargetByEngine,

		// Convert reduction setting options
		ConvertReductionSettingOptions,

		// Serialize the type of blending used for landscape layer weight static params
		StaticParameterTerrainLayerWeightBlendType,
	
		// Fix up None Named animation curve names, 
		FixUpNoneNameAnimationCurves, 

		// Ensure ActiveBoneIndices to have parents even not skinned for old assets
		EnsureActiveBoneIndicesToContainParents,

		// Serialize the instanced static mesh render data, to avoid building it at runtime
		SerializeInstancedStaticMeshRenderData,

		// Cache material quality node usage
		CachedMaterialQualityNodeUsage,
		
		// Font outlines no longer apply to drop shadows for new objects but we maintain the opposite way for backwards compat
		FontOutlineDropShadowFixup,

		// New skeletal mesh import workflow (Geometry only or animation only re-import )
		NewSkeletalMeshImporterWorkflow,

		// Migrate data from previous data structure to new one to support materials per LOD on the Landscape
		NewLandscapeMaterialPerLOD,

		// New Pose Asset data type
		RemoveUnnecessaryTracksFromPose, 

		// Migrate Foliage TLazyObjectPtr to TSoftObjectPtr
		FoliageLazyObjPtrToSoftObjPtr,

		// TimelineTemplates store their derived names instead of dynamically generating
		// This code tied to this version was reverted and redone at a later date
		REVERTED_StoreTimelineNamesInTemplate,

		// Added BakePoseOverride for LOD setting
		AddBakePoseOverrideForSkeletalMeshReductionSetting,

		// TimelineTemplates store their derived names instead of dynamically generating
		StoreTimelineNamesInTemplate,
		
		// Avoid duplicating widget animations to save space.
		WidgetStopDuplicatingAnimations,

		// Allow reducing of the base LOD, we need to store some imported model data so we can reduce again from the same data.
		AllowSkeletalMeshToReduceTheBaseLOD,

		// Curve Table size reduction
		ShrinkCurveTableSize,

		// Widgets upgraded with WidgetStopDuplicatingAnimations, may not correctly default-to-self for the widget parameter.
		WidgetAnimationDefaultToSelfFail,

		// HUDWidgets now require an element tag
		FortHUDElementNowRequiresTag,

		// Animation saved as bulk data when cooked
		FortMappedCookedAnimation,

		// Support Virtual Bone in Retarget Manager
		SupportVirtualBoneInRetargeting,

		// Fixup bad defaults in water metadata
		FixUpWaterMetadata,

		// Move the location of water metadata
		MoveWaterMetadataToActor,

		// Replaced lake collision component
		ReplaceLakeCollision,

		// Anim layer node names are now conformed by Guid
		AnimLayerGuidConformation,

		// Ocean collision component has become dynamic
		MakeOceanCollisionTransient,

		// FFieldPath will serialize the owner struct reference and only a short path to its property
		FFieldPathOwnerSerialization,

		// Simplified WaterBody post process material handling 
		FixUpUnderwaterPostProcessMaterial,

		// A single water exclusion volume can now exclude N water bodies
		SupportMultipleWaterBodiesPerExclusionVolume,

		// Serialize rigvm operators one by one instead of the full byte code array to ensure determinism
		RigVMByteCodeDeterminism,

		// Serialize the physical materials generated by the render material
		LandscapePhysicalMaterialRenderData,

		// RuntimeVirtualTextureVolume fix transforms
		FixupRuntimeVirtualTextureVolume,

		// Retrieve water body collision components that were lost in cooked builds
		FixUpRiverCollisionComponents,

		// Fix duplicate spline mesh components on rivers
		FixDuplicateRiverSplineMeshCollisionComponents,

		// Indicates level has stable actor guids
		ContainsStableActorGUIDs,

		// Levelset Serialization support for BodySetup.
		LevelsetSerializationSupportForBodySetup,

		// Moving Chaos solver properties to allow them to exist in the project physics settings
		ChaosSolverPropertiesMoved,

		// Moving some UFortGameFeatureData properties and behaviors into the UGameFeatureAction pattern
		GameFeatureData_MovedComponentListAndCheats,

		// Add centrifugal forces for cloth
		ChaosClothAddfictitiousforces,

		// Chaos Convex StructureData supports different index sizes based on num verts/planes
		// Chaos FConvex uses array of FVec3s for vertices instead of particles
		// (Merged from //UE4/Main)
		ChaosConvexVariableStructureDataAndVerticesArray,

		// Remove the WaterVelocityHeightTexture dependency on MPC_Landscape and LandscapeWaterIndo 
		RemoveLandscapeWaterInfo,

		// Added the weighted value property type to store the cloths weight maps' low/high ranges
		ChaosClothAddWeightedValue,

		// Added the Long Range Attachment stiffness weight map
		ChaosClothAddTetherStiffnessWeightMap,

		// Fix corrupted LOD transition maps
		ChaosClothFixLODTransitionMaps,

		// Enable a few more weight maps to better art direct the cloth simulation
		ChaosClothAddTetherScaleAndDragLiftWeightMaps,

		// Enable material (edge, bending, and area stiffness) weight maps
		ChaosClothAddMaterialWeightMaps,

		// Added bShowCurve for movie scene float channel serialization
		SerializeFloatChannelShowCurve,

		// Minimize slack waste by using a single array for grass data
		LandscapeGrassSingleArray,

		// Add loop counters to sequencer's compiled sub-sequence data
		AddedSubSequenceEntryWarpCounter,

		// Water plugin is now component-based rather than actor based
		WaterBodyComponentRefactor,

		// Cooked BPGC storing editor-only asset tags
		BPGCCookedEditorTags,

		// Terrain layer weights are no longer considered material parameters
		TerrainLayerWeightsAreNotParameters,

		// Anim Dynamics Node Gravity Override vector is now defined in world space, not simulation space. 
		// Legacy behavior can be maintained with a flag, which is set false by default for new nodes, 
		// true for nodes predating this change.
		GravityOverrideDefinedInWorldSpace,

		// Anim Dynamics Node Physics parameters for each body in a chain are now stored in an array and can be edited.
		AnimDynamicsEditableChainParameters,

		// Decoupled the generation of the water texture from the Water Brush and the landscape
		WaterZonesRefactor,

		// Add faster damping calculations to the cloth simulation and rename previous Damping parameter to LocalDamping.
		ChaosClothFasterDamping,

		// Migrated function handlers to the CDO/archetype data
		MigratedFunctionHandlersToDefaults,

		// Storing inertia tensor as vec3 instead of matrix.
		ChaosInertiaConvertedToVec3,

		// Migrated event definitions to the CDO/archetype data
		MigratedEventDefinitionToDefaults,

		// Serialize LevelInstanceActorGuid on new ILevelInstanceInterface implementation
		LevelInstanceActorGuidSerialize,

		// Single-frame/key AnimDataModel patch-up
		SingleFrameAndKeyAnimModel,

		// Remapped bEvaluateWorldPositionOffset to bEvaluateWorldPositionOffsetInRayTracing
		RemappedEvaluateWorldPositionOffsetInRayTracing,

		// Water body collision settings are now those of the base UPrimitiveComponent, rather than duplicated in UWaterBodyComponent
		WaterBodyComponentCollisionSettingsRefactor,

		// Introducing widget inherited named slots.  This wouldn't have required a version bump, except in the previous
		// version, users could make NamedSlots and then Seed them with any random widgets, as a sorta 'default' setup.
		// In order to preserve that, we're bumping the version so that we can set a new field on UNamedSlot to control
		// if a widget exposes its named slot to everyone (even if it has content), which by default they wont any longer.
		WidgetInheritedNamedSlots,

		// Added water HLOD material
		WaterHLODSupportAdded,

		// Moved parameters affecting Skeleton pose rendering from the PoseWatch class to the PoseWatchPoseElement class.
		PoseWatchMigrateSkeletonDrawParametersToPoseElement,

		// Reset default value for Water exclusion volumes to make them more intuitive and support the "it just works" philosophy.
		WaterExclusionVolumeExcludeAllDefault,
		
		// Added water non-tessellated LOD
		WaterNontessellatedLODSupportAdded,

		// Added FHierarchicalSimplification::SimplificationMethod
		HierarchicalSimplificationMethodEnumAdded,

		// Changed how world partition streaming cells are named
		WorldPartitionStreamingCellsNamingShortened,

		// Serialize ContentBundleGuid in WorldPartitionActorDesc
		WorldPartitionActorDescSerializeContentBundleGuid,

		// Serialize IsActorRuntimeOnly in WorldPartitionActorDesc
		WorldPartitionActorDescSerializeActorIsRuntimeOnly,

		// Add Nanite Material Override option to materials and material instances.
		NaniteMaterialOverride,

		// Serialize HLOD stats in HLODActorDesc
		WorldPartitionHLODActorDescSerializeStats,

		// WorldPartitionStreamingSourceComponent property deprecation
		WorldPartitionStreamingSourceComponentTargetDeprecation,

		// Fixed localization gathering for external actor packages
		FixedLocalizationGatherForExternalActorPackage,

		// Change HLODActors to RuntimeCells mapping to use a GUID instead of the cell name
		WorldPartitionHLODActorUseSourceCellGuid,

		// Add an attribute to geometry collection to track internal faces, rather than relying on material ID numbering
		ChaosGeometryCollectionInternalFacesAttribute,

		// Dynamic cast nodes use an enumerated pure node state to include a value for the default setting
		DynamicCastNodesUsePureStateEnum,

		// Add FWorldPartitionActorFilter to FLevelInstanceActorDesc/FDataLayerInstanceDesc
		WorldPartitionActorFilter,

		// Change the non-spatialized radius to blend to a pure 2D spatialized sound vs omnidirectional
		AudioAttenuationNonSpatializedRadiusBlend,

		// Serialize actor class descriptors
		WorldPartitionActorClassDescSerialize,

		// FActorContainerID is now an FGuid instead of a uint64
		WorldPartitionFActorContainerIDu64ToGuid,

		// FDataLayerInstanceDesc support for private data layers
		WorldPartitionPrivateDataLayers,

		// Reduce size and improve behaviour of Chaos::FImplicitObjectUnion
		ChaosImplicitObjectUnionBVHRefactor,

		// FLevelInstanceActorDesc DeltaSerialize Filter
		LevelInstanceActorDescDeltaSerializeFilter,

		// Fix the Nanite landscape mesh non-deterministic DDC keys
		FixNaniteLandscapeMeshDDCKey,

		// Change how connection graphs are stored on Geometry Collections to an edge-array representation
		ChaosGeometryCollectionConnectionEdgeGroup,

		// Moved the water info mesh data and static water body meshes into new static mesh components for water bodies.
		WaterBodyStaticMeshComponents,

		// Serialize invalid bounds in world partition actor descriptors
		WorldPartitionActorDescSerializeInvalidBounds,

		// Upgrade Navigation Links to use 64 bits for the ID
		NavigationLinkID32To64,

		// Serialize editor only references in world partition actor descriptors
		WorldPartitionActorDescSerializeEditorOnlyReferences,

		// Add support for soft object paths in actor descriptors
		WorldPartitionActorDescSerializeSoftObjectPathSupport,

		// Don't serialize class descriptor GUIDs
		WorldPartitionClasDescGuidTransient,

		// Serialize ActorDesc bIsMainWorldOnly
		WorldPartitionActorDescIsMainWorldOnly,

		// FWorldPartitionActorFilter go back to FString serialize of AssetPaths to avoid FArchiveReplaceOrClearExternalReferences clearing CDO references on BP Compile
		WorldPartitionActorFilterStringAssetPath,

		// Add FPackedLevelActorDesc for APackedLevelActor and support for APackedLevelActor Filters
		PackedLevelActorDesc,

		// Add customizable values for several UWorldPartitionRuntimeSpatialHash cvars
		WorldPartitionRuntimeSpatialHashCVarOverrides,

		// WorldPartition HLOD now contains a source actors object
		WorldPartitionHLODSourceActorsRefactor,

		WaterBodyStaticMeshRename,

		// Geometry Collection now by-default converts vertex colors to sRGB when creating render data
		GeometryCollectionConvertVertexColorToSRGB,

		// Water bodies before this version need to update their water zone on load since they won't have been serialized yet.
		WaterOwningZonePointerFixup,

		// Set flags on water static meshes to duplicate transient to avoid underlying static mesh duplication issue
		WaterBodyStaticMeshDuplicateTransient,

		// Update paths to use the SkeletalClass
		MVVMConvertPropertyPathToSkeletalClass,

		// Fixup all flags/outering on static meshes on water bodies by rebuilding them completely
		WaterBodyStaticMeshFixup,

		// -----<new versions can be added above this line>-------------------------------------------------
		VersionPlusOne,
		LatestVersion = VersionPlusOne - 1
	};

	// The GUID for this custom version number
	CORE_API const static FGuid GUID;

	static CORE_API TMap<FGuid, FGuid> GetSystemGuids();

private:
	FFortniteMainBranchObjectVersion() {}
};
