/* Main Simulation File */
#include "NewtonCooling_model.h"
#include "simulation/solver/events.h"

#define prefixedName_performSimulation NewtonCooling_performSimulation
#define prefixedName_updateContinuousSystem NewtonCooling_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation NewtonCooling_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int NewtonCooling_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int NewtonCooling_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
 equation index: 3
 type: SIMPLE_ASSIGN
 der(T) = h * A * (T_inf - T) / (m * c_p)
 */
void NewtonCooling_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[1] /* der(T) STATE_DER */ = DIVISION_SIM((data->simulationInfo->realParameter[4]) * ((data->simulationInfo->realParameter[0]) * (data->simulationInfo->realParameter[2] - data->localData[0]->realVars[0] /* T STATE(1) */)),(data->simulationInfo->realParameter[5]) * (data->simulationInfo->realParameter[3]),"m * c_p",equationIndexes);
  TRACE_POP
}

OMC_DISABLE_OPT
int NewtonCooling_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  NewtonCooling_functionLocalKnownVars(data, threadData);
  NewtonCooling_eqFunction_3(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int NewtonCooling_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void NewtonCooling_eqFunction_3(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
    NewtonCooling_eqFunction_3(data, threadData);
}

int NewtonCooling_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  NewtonCooling_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

  
  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "NewtonCooling_12jac.h"
#include "NewtonCooling_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks NewtonCooling_callback = {
   (int (*)(DATA *, threadData_t *, void *)) NewtonCooling_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) NewtonCooling_performQSSSimulation,
   NewtonCooling_updateContinuousSystem,
   NewtonCooling_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   NewtonCooling_initializeStateSets,
   #else
   NULL,
   #endif
   NewtonCooling_initializeDAEmodeData,
   NewtonCooling_functionODE,
   NewtonCooling_functionAlgebraics,
   NewtonCooling_functionDAE,
   NewtonCooling_functionLocalKnownVars,
   NewtonCooling_input_function,
   NewtonCooling_input_function_init,
   NewtonCooling_input_function_updateStartValues,
   NewtonCooling_output_function,
   NewtonCooling_function_storeDelayed,
   NewtonCooling_updateBoundVariableAttributes,
   NewtonCooling_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NewtonCooling_functionInitialEquations_lambda0,
   NewtonCooling_functionRemovedInitialEquations,
   NewtonCooling_updateBoundParameters,
   NewtonCooling_checkForAsserts,
   NewtonCooling_function_ZeroCrossingsEquations,
   NewtonCooling_function_ZeroCrossings,
   NewtonCooling_function_updateRelations,
   NewtonCooling_zeroCrossingDescription,
   NewtonCooling_relationDescription,
   NewtonCooling_function_initSample,
   NewtonCooling_INDEX_JAC_A,
   NewtonCooling_INDEX_JAC_B,
   NewtonCooling_INDEX_JAC_C,
   NewtonCooling_INDEX_JAC_D,
   NewtonCooling_initialAnalyticJacobianA,
   NewtonCooling_initialAnalyticJacobianB,
   NewtonCooling_initialAnalyticJacobianC,
   NewtonCooling_initialAnalyticJacobianD,
   NewtonCooling_functionJacA_column,
   NewtonCooling_functionJacB_column,
   NewtonCooling_functionJacC_column,
   NewtonCooling_functionJacD_column,
   NewtonCooling_linear_model_frame,
   NewtonCooling_linear_model_datarecovery_frame,
   NewtonCooling_mayer,
   NewtonCooling_lagrange,
   NewtonCooling_pickUpBoundsForInputsInOptimization,
   NewtonCooling_setInputData,
   NewtonCooling_getTimeGrid,
   NewtonCooling_symbolicInlineSystem,
   NewtonCooling_function_initSynchronous,
   NewtonCooling_function_updateSynchronous,
   NewtonCooling_function_equationsSynchronous,
   NewtonCooling_inputNames,
   NULL,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "NewtonCooling"
#define _OMC_LIT_RESOURCE_0_dir_data "/home/cma/Desktop/modelica-trivial/model-newton-cooling"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,13,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,55,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void NewtonCooling_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &NewtonCooling_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "NewtonCooling";
  data->modelData->modelFilePrefix = "NewtonCooling";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/cma/Desktop/modelica-trivial/model-newton-cooling";
  data->modelData->modelGUID = "{da1970a4-d2e0-478a-a302-831ac4b38a92}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "NewtonCooling_init.c"
    ;
  static const char contents_info[] =
    #include "NewtonCooling_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "NewtonCooling_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "NewtonCooling_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 1;
  data->modelData->nVariablesReal = 2;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 6;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "NewtonCooling_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 11;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 4;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

#ifdef __cplusplus
}
#endif

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    NewtonCooling_setupDataStruc(&data, threadData);
    res = _main_SimulationRuntime(argc, argv, &data, threadData);
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}

