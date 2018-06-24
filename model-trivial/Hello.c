/* Main Simulation File */
#include "Hello_model.h"
#include "simulation/solver/events.h"

#define prefixedName_performSimulation Hello_performSimulation
#define prefixedName_updateContinuousSystem Hello_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation Hello_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int Hello_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Hello_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Hello_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Hello_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Hello_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
 equation index: 3
 type: SIMPLE_ASSIGN
 der(x) = -x
 */
void Hello_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[1] /* der(x) STATE_DER */ = (-data->localData[0]->realVars[0] /* x STATE(1) */);
  TRACE_POP
}

OMC_DISABLE_OPT
int Hello_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Hello_functionLocalKnownVars(data, threadData);
  Hello_eqFunction_3(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int Hello_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void Hello_eqFunction_3(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
    Hello_eqFunction_3(data, threadData);
}

int Hello_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Hello_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

  
  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Hello_12jac.h"
#include "Hello_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Hello_callback = {
   (int (*)(DATA *, threadData_t *, void *)) Hello_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) Hello_performQSSSimulation,
   Hello_updateContinuousSystem,
   Hello_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   Hello_initializeStateSets,
   #else
   NULL,
   #endif
   Hello_initializeDAEmodeData,
   Hello_functionODE,
   Hello_functionAlgebraics,
   Hello_functionDAE,
   Hello_functionLocalKnownVars,
   Hello_input_function,
   Hello_input_function_init,
   Hello_input_function_updateStartValues,
   Hello_output_function,
   Hello_function_storeDelayed,
   Hello_updateBoundVariableAttributes,
   Hello_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   Hello_functionInitialEquations_lambda0,
   Hello_functionRemovedInitialEquations,
   Hello_updateBoundParameters,
   Hello_checkForAsserts,
   Hello_function_ZeroCrossingsEquations,
   Hello_function_ZeroCrossings,
   Hello_function_updateRelations,
   Hello_zeroCrossingDescription,
   Hello_relationDescription,
   Hello_function_initSample,
   Hello_INDEX_JAC_A,
   Hello_INDEX_JAC_B,
   Hello_INDEX_JAC_C,
   Hello_INDEX_JAC_D,
   Hello_initialAnalyticJacobianA,
   Hello_initialAnalyticJacobianB,
   Hello_initialAnalyticJacobianC,
   Hello_initialAnalyticJacobianD,
   Hello_functionJacA_column,
   Hello_functionJacB_column,
   Hello_functionJacC_column,
   Hello_functionJacD_column,
   Hello_linear_model_frame,
   Hello_linear_model_datarecovery_frame,
   Hello_mayer,
   Hello_lagrange,
   Hello_pickUpBoundsForInputsInOptimization,
   Hello_setInputData,
   Hello_getTimeGrid,
   Hello_symbolicInlineSystem,
   Hello_function_initSynchronous,
   Hello_function_updateSynchronous,
   Hello_function_equationsSynchronous,
   Hello_inputNames,
   NULL,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Hello"
#define _OMC_LIT_RESOURCE_0_dir_data "/home/cma/Desktop/modelica-trivial/model-trivial"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,5,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,48,_OMC_LIT_RESOURCE_0_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,2,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir)}};
void Hello_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Hello_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Hello";
  data->modelData->modelFilePrefix = "Hello";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/cma/Desktop/modelica-trivial/model-trivial";
  data->modelData->modelGUID = "{001d1333-dd34-4c5e-98d7-cc8767a3cd2e}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "Hello_init.c"
    ;
  static const char contents_info[] =
    #include "Hello_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "Hello_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "Hello_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 1;
  data->modelData->nVariablesReal = 2;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 0;
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
  data->modelData->modelDataXml.fileName = "Hello_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 4;
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
  
    Hello_setupDataStruc(&data, threadData);
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

