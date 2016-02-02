/**
    \file lib_c_api.h
    C API for stamina library
*/

#ifndef __LIB_C_API_H__
#define __LIB_C_API_H__

#include "../../lib_core/src/stamina.h"

#ifndef MCU
// wraper for other language, e.g. python
extern "C" {

	/*! \fn User* User_new()
		\brief New a default user object having stamina analysis functions.
		\return a user object
	*/
	User* User_new();

	/*! \fn User *User_new_with(int pAge, int pGender, int pWeight, int pHeight, int pBioMaxHr, int pBioMaxHrSportType, int pBioRestHr, double pFatPtc, double pMusclePtc, double pBonePtc, double pWaterPtc, long pMaxRecordingLength, double pAeroTotalCapacity, double pAeroCapacity, int pLADilutionGrade, double pAnaerobicPtc)
		\brief New a user object having stamina analysis functions with specific user parameters.
		\return a user object
		
		\par Example:
		\code{.cpp}
		User* user_ptr = User_new_with(int pAge, 
									   int pGender, 
									   int pWeight, 
									   int pHeight, 
									   int pBioMaxHr, 
									   int pBioMaxHrSportType, 
									   int pBioRestHr, 
									   double pFatPtc, 
									   double pMusclePtc, 
									   double pBonePtc, 
									   double pWaterPtc, 
									   long pMaxRecordingLength, 
									   double pAeroTotalCapacity, 
									   double pAeroCapacity, 
									   int pLADilutionGrade, 
									   double pAnaerobicPtc)
		\endcode
	*/
	User* User_new_with(int pAge, /**< [in] [int] Age of user. Valid range from 10 ~ 100. */
				        int pGender, /**< [in] gender of user */
				        int pWeight, /**< [in] weight of user */
				        int pHeight, /**< [in] height of user */
				        int pBioMaxHr, /**< [in] bio max HR of user */
				        int pBioMaxHrSportType,
				        int pBioRestHr,
				        double pFatPtc,
				        double pMusclePtc,
				        double pBonePtc,
				        double pWaterPtc,
				        long pMaxRecordingLength,
				        double pAeroTotalCapacity,
				        double pAeroCapacity,
				        int pLADilutionGrade,
				        double pAnaerobicPtc);

	int User_update_new_heartrate_status(User* pUserPtr, 
								  long pTimeSec, 
	  	 						  int pHr,
	  	 						  int pHrQuality,
	  	 						  int pHrPosition,
	  	 						  int pDeviceBrand,
	  	 						  int pRRI1,
	  	 						  int pRRI2,
	  	 						  int pRRI3,
	  	 						  int pRRI4,
	  	 						  int pRRI5,
	  	 						  int pRRI6);

	int User_update_new_physic_status(User* pUserPtr,
								      long pTimeSec,
								      double pSessionDistKm,
						       	      double pSpeedKmph,
						       	      int pExerciseType,
						       	      double pFrontArea,
						       	      double pSlopGrade,
						       	      double pWindSpeedKmph,
						       	      double pAirTemp,
						       	      double pLongitude,
						       	      double pLatitude,
						       	      double pAltitude,
						       	      double pPower,
						       	      double pCadence);

	double User_get_user_now_meta_session_total_kcal(User* pUserPtr);

	double User_get_user_now_meta_session_exercise_kcal(User* pUserPtr);

	double User_get_user_now_meta_session_BMR_kcal(User* pUserPtr);

	double User_get_user_now_stamina_ptc(User* pUserPtr);

	double User_get_user_now_aerobic_ptc(User* pUserPtr);

	double User_get_user_now_anaerobic_ptc(User* pUserPtr);

	double User_get_user_now_aero_capacity(User* pUserPtr);

	double User_get_user_now_aero_total_capacity(User* pUserPtr);

	double User_get_user_now_lacid(User* pUserPtr);

	int User_get_user_now_LA_dilution_grade(User* pUserPtr);

	double User_get_user_now_predicted_avg_pace_max_conti_burn(User* pUserPtr);

	double User_get_user_now_predicted_avg_pace_max_burn_with_stamina_left(User* pUserPtr);

	double User_get_user_now_predicted_last_pace_max_conti_burn(User* pUserPtr);

	double User_get_user_now_predicted_last_pace_max_burn_with_stamina_left(User* pUserPtr);

	double User_get_user_now_predicted_avg_pace_max_conti_dist_km(User* pUserPtr);

	double User_get_user_now_predicted_avg_pace_time_sec_for_max_conti_dist(User* pUserPtr);

	double User_get_user_now_predicted_avg_pace_max_dist_km_with_stamina_left(User* pUserPtr);

	double User_get_user_now_predicted_last_pace_max_conti_dist_km(User* pUserPtr);

	double User_get_user_now_predicted_last_pace_time_sec_for_max_conti_dist(User* pUserPtr);

	double User_get_user_now_predicted_last_pace_max_dist_km_with_stamina_left(User* pUserPtr);

	double User_get_user_now_predicted_sudo_VDOT(User* pUserPtr);

	double User_get_user_session_VDOT(User* pUserPtr);

	long User_get_user_now_heartD_time(User* pUserPtr);

	long User_get_user_now_staminaD_time(User* pUserPtr);

	long User_get_user_now_physicD_time(User* pUserPtr);

	long User_get_user_now_predicted_burn_time(User* pUserPtr);

	long User_get_user_now_predicted_dist_time(User* pUserPtr);

	// HRR calculation
	int User_get_user_HR_by_HRR_0(User* pUserPtr);

	int User_get_user_HR_by_HRR_50(User* pUserPtr);

	int User_get_user_HR_by_HRR_60(User* pUserPtr);

	int User_get_user_HR_by_HRR_70(User* pUserPtr);

	int User_get_user_HR_by_HRR_80(User* pUserPtr);

	int User_get_user_HR_by_HRR_90(User* pUserPtr);

	int User_get_user_HR_by_HRR_100(User* pUserPtr);

	int User_get_user_HR_by_HRR_D_UP_59(User* pUserPtr);

	int User_get_user_HR_by_HRR_E_UP_74(User* pUserPtr);

	int User_get_user_HR_by_HRR_M_UP_84(User* pUserPtr);

	int User_get_user_HR_by_HRR_T_UP_88(User* pUserPtr);

	int User_get_user_HR_by_HRR_A_UP_95(User* pUserPtr);

	int User_get_user_HR_by_HRR_I_UP_100(User* pUserPtr);

	int User_update_aerobic_anaerobic_result_by_question(User* pUserPtr,
												         int pFirstTime,
								 			             int pAnswerBreath,
								 			             int pAnswerMuscle,
								 			             int pAnswerRPE);
}

#endif

#endif