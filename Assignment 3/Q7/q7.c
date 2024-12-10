/*Question 07
In a Netflix-like streaming platform, 2D pointers are used to dynamically manage and personalize
...............................................................................................
needs of a global user base.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *title;
    float rating;
    int runtime;
    char *encoding_format;
}ContentMetadata;

typedef struct{
    double **engagementMatrix;
    
    char **resolutionPreferences;
     char **playbackHistory;
    
    float *bandwidthUsage;
}DevicePreferences;

double** createEngagementMatrix(int users, int categories)
//function stat
{
    double **matrix= (double**)malloc(users * sizeof(double*));
    for(int i =0; i<users;i++)
    {

         matrix[i] = (double*)malloc(categories * sizeof(double));
        for(int j= 0; j <categories;j++)
        {//start for in
             matrix[i][j] = 0.0;
        }//end for in
    }//end for out
  
    return matrix;
}//end func

DevicePreferences* createDevicePreferences(int devices)

{
    DevicePreferences *prefs=(DevicePreferences*)malloc(sizeof(DevicePreferences));
  
    prefs -> resolutionPreferences = (char**)malloc(devices * sizeof(char*));
    prefs ->playbackHistory = (char**)malloc(devices * sizeof(char*));
    prefs ->bandwidthUsage = (float*)malloc(devices * sizeof(float));
    for(int i=0; i<devices;i++)
    {
        prefs-> resolutionPreferences[i] = strdup ("1080p");
        prefs->playbackHistory[i] = strdup ("None");
//rt
        prefs-> bandwidthUsage[i] = 0.0;
    }
   
    return prefs;

}

ContentMetadata** createContentMetadata(int categories, int pieces)
{
  
   ContentMetadata **metadata = (ContentMetadata**)malloc(categories * sizeof(ContentMetadata*));
   
    for(int i = 0; i < categories; i++)
    {
   
        metadata[i]=(ContentMetadata*)malloc(pieces * sizeof(ContentMetadata));
        for(int j=0;j<pieces;j++)
        {
            metadata[i][j].title = strdup("Untitled");
            
            metadata[i][j].rating = 0.0;
             metadata[i][j].runtime = 0;
            metadata[i][j].encoding_format = strdup("H.264");
        }

    }
  
   return metadata;
}

void updateEngagement(double **matrix, int userIndex, int categoryIndex, double score)
{
    if(userIndex>=0 && categoryIndex>=0)
    {
        matrix[userIndex][categoryIndex]=score;
    }
}

void printEngagementMatrix(double **matrix, int users, int categories)
{
    for(int i = 0; i < users; i++)
   
    {


        for(int j = 0; j < categories; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
       
        printf("\n");
    }
}

int main()
{
   
    int users = 3;  //the input is defined you can change it here
    int categories = 3;
    int devices = 2;
   
    int pieces = 2;

    double **engagementMatrix = createEngagementMatrix(users, categories);
     DevicePreferences *devicePrefs = createDevicePreferences(devices);
   
    ContentMetadata **contentMetadata = createContentMetadata(categories, pieces);

        updateEngagement(engagementMatrix, 0, 1, 5.0);
      updateEngagement(engagementMatrix, 1, 2, 4.2);

    
    printEngagementMatrix(engagementMatrix, users, categories);

    for(int i = 0; i < users; i++)
    {
        free(engagementMatrix[i]);
    
    }
    
    free(engagementMatrix);

    for(int i = 0; i < devices; i++)
    {
    
        free(devicePrefs->resolutionPreferences[i]);
        free(devicePrefs->playbackHistory[i]);
    }
    free(devicePrefs->resolutionPreferences);
    free(devicePrefs->playbackHistory);

    free(devicePrefs->bandwidthUsage);
    free(devicePrefs);


     
     for(int i = 0; i < categories; i++)
    
    {
        for(int j = 0; j < pieces; j++)
        {
    
            free(contentMetadata[i][j].title);
                free(contentMetadata[i][j].encoding_format);
    
        }
    
        free(contentMetadata[i]);
    
    }
    
    free(contentMetadata);

    return 0;
}