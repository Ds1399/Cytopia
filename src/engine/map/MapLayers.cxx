#include "MapLayers.hxx"

// static variables
unsigned int MapLayers::m_activeLayers = 0;

void MapLayers::setLayerEditMode(LayerEditMode layerEditMode)
{
  bool showBuildingsInBlueprint = true; // TODO IMPORTANT should be ettings::instance().showBuildingsInBlueprint

  {
    switch (layerEditMode)
    {
    case LayerEditMode::BLUEPRINT:
      deactivateAllLayers();
      if (showBuildingsInBlueprint)
      {
        enableLayers({ BUILDINGS });
      }
      enableLayers({BLUEPRINT, UNDERGROUND, ROAD});
      break;
    case LayerEditMode::TERRAIN:
      deactivateAllLayers();
      enableLayers({TERRAIN, WATER, ROAD, ZONE, BUILDINGS});
      break;
    }
  };
}

void MapLayers::enableLayers(std::vector<unsigned int> &&layers)
{
  unsigned int enLayers = 0U;

  for (auto layer : layers)
  {
    enLayers |= 1U << layer;
  }

  m_activeLayers |= enLayers;
}
