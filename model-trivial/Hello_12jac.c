/* Jacobians 4 */
#include "Hello_model.h"
#include "Hello_12jac.h"
int Hello_initialAnalyticJacobianD(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Hello_initialAnalyticJacobianC(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Hello_initialAnalyticJacobianB(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
OMC_DISABLE_OPT
int Hello_initialAnalyticJacobianA(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Hello_INDEX_JAC_A;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int Hello_functionJacD_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Hello_functionJacC_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Hello_functionJacB_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Hello_functionJacA_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Hello_INDEX_JAC_A;
  
  TRACE_POP
  return 0;
}


