/*
** main.c
** 
** Made by (Sean Dague)
** Login   <sdague@orac>
** 
** Started on  Fri Apr 16 10:48:16 2010 Sean Dague
** Last update Sun May 12 01:17:25 2002 Speed Blue
*/
#include <stdio.h>
#include <time.h>
#include "l1.h"

#include <jni.h>
// #include "ArrayHandler.h"

jdoubleArray Java_net_dague_astro_sim_SolarSim_mercuryCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double mercury[3];
    get_mercury_helio_coordsv(jd, mercury);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) mercury );

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_venusCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double venus[3];
    get_venus_helio_coordsv(jd, venus);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) venus );

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_earthCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double earth[3];
    get_earth_helio_coordsv(jd, earth);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) earth ); 

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_marsCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double mars[3];
    get_mars_helio_coordsv(jd, mars);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) mars );

    return answer;
}


jdoubleArray Java_net_dague_astro_sim_SolarSim_jupiterCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double jupiter[3];
    get_jupiter_helio_coordsv(jd, jupiter);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) jupiter ); 

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_saturnCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double saturn[3];
    get_saturn_helio_coordsv(jd, saturn);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) saturn );

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_uranusCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double uranus[3];
    get_uranus_helio_coordsv(jd, uranus);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) uranus );

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_neptuneCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double neptune[3];
    get_neptune_helio_coordsv(jd, neptune);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) neptune );

    return answer;
}


jdoubleArray Java_net_dague_astro_sim_SolarSim_ioCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double io[3];
    get_io_parent_coordsv(jd, io);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) io ); 

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_europaCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double europa[3];
    get_europa_parent_coordsv(jd, europa);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) europa ); 

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_ganymedeCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double ganymede[3];
    get_ganymede_parent_coordsv(jd, ganymede);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) ganymede ); 

    return answer;
}

jdoubleArray Java_net_dague_astro_sim_SolarSim_callistoCoords(JNIEnv *env, jobject jobj, jdouble jd) {
    double callisto[3];
    get_callisto_parent_coordsv(jd, callisto);

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) callisto ); 

    return answer;
}


jdoubleArray Java_net_dague_astro_sim_SolarSim_returnJD(JNIEnv *env, jobject jobj, jdouble jd) {

    /* jdouble ret; */

    /* ret = jd; */
    /* int i; */
    /* jint n = 3; */

    double three[3];
    three[0] = jd;
    three[1] = jd;
    three[2] = jd;

    jdoubleArray answer = (*env)->NewDoubleArray(env, 3);
    (*env)->SetDoubleArrayRegion( env, answer, 0, 3, (const jdouble*) three ); 
    
    /* jdouble* destArrayElems = (*env)->GetDoubleArrayElements(env, data, 0); */
    
    
    /* destArrayElems[0] = jd;  */
    /* destArrayElems[1] = jd; */
    /* destArrayElems[2] = jd; */

    /* if (isCopy2 == JNI_TRUE) { */
    /*     (*env)->ReleaseDoubleArrayElements(env, ret, destArrayElems, 0); */
    /* } */

    return answer;
}
