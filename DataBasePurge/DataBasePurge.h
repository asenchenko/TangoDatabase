//=============================================================================
//
// file :        DataBasePurge.h
//
// description : Include for the DataBasePurge class.
//
// project :	DataBasePurge
//
// $Author$
//
// $Revision$
//
// $Log$
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _DATABASEPURGE_H
#define _DATABASEPURGE_H

#include <tango.h>
#include <mysql.h>

//using namespace Tango;

/**
 * @author	$Author$
 * @version	$Revision$
 */

 //	Add your own constants definitions here.
 //-----------------------------------------------


namespace DataBasePurge_ns
{

  class PurgeThread;

/**
 * Class Description:
 * Perform purge of tango database history tables.
 */

/*
 *	Device States Description:
 */


class DataBasePurge: public Tango::Device_3Impl
{
public :
	//	Add your own data members here
	//-----------------------------------------


	//	Here is the Start of the automatic code generation part
	//-------------------------------------------------------------	
/**
 *	@name attributes
 *	Attributs member data.
 */
//@{
//@}

/**
 *	@name Device properties
 *	Device properties member data.
 */
//@{
/**
 *	Property history depth
 */
	Tango::DevLong	history_depth;
/**
 *	Purge period (sec)
 */
	Tango::DevLong	purge_Period;
//@}

/**@name Constructors
 * Miscellaneous constructors */
//@{
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	DataBasePurge(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	DataBasePurge(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device name
 *	@param d	Device description.
 */
	DataBasePurge(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one desctructor is defined for this class */
//@{
/**
 * The object desctructor.
 */	
	~DataBasePurge() {delete_device();};
/**
 *	will be called at device destruction or at init command.
 */
	void delete_device();
//@}

	
/**@name Miscellaneous methods */
//@{
/**
 *	Initialize the device
 */
	virtual void init_device();
/**
 *	Always executed method befor execution command method.
 */
	virtual void always_executed_hook();

//@}

/**
 * @name DataBasePurge methods prototypes
 */

//@{

/**
 *	Read the device properties from database
 */
	 void get_device_property();
//@}

	//	Here is the end of the automatic code generation part
	//-------------------------------------------------------------	



protected :	
	//	Add your own data members here
	//-----------------------------------------
	MYSQL mysql; 
	PurgeThread *purgeThread;

public:
	int thread_alive;
	int purge_in_progress;
	double purge_progress;
	void simple_query(string sql_query);
        MYSQL_RES *query(string sql_query);
};

}	// namespace_ns

#endif	// _DATABASEPURGE_H