//####################################################################
//
//    FILENAME:   CSMWarning.h
//
//    CLASSIFICATION:    Unclassified
//
//    DESCRIPTION:
//
//    Header for the warning structure used by the CSM.
//
//    LIMITATIONS:       None
//
//
//    SOFTWARE HISTORY:
//     Date          Author   Comment   
//     -----------   ------   -------
//     01-Jun-2004   Kevin Lam CCB Change
//     02-Mar-2012   SCM       Refactored interface.
//
//    NOTES:
//
//###################################################################

#ifndef __CSMWARNING_H
#define __CSMWARNING_H

#include "CSMMisc.h"
#include <string>
#include <list>

namespace csm {

class CSM_EXPORT_API Warning
{
public:
   enum WarningType
   {
      UNKNOWN_WARNING = 1,
      DATA_NOT_AVAILABLE,
      PRECISION_NOT_MET,
      NEGATIVE_PRECISION,
      IMAGE_COORD_OUT_OF_BOUNDS,
      IMAGE_ID_TOO_LONG,
      NO_INTERSECTION,
      DEPRECATED_FUNCTION
   };

   Warning() : theWarning(UNKNOWN_WARNING), theMessage(), theFunction() {}

   Warning(const WarningType& aWarningType,
           const std::string& aMessage,
           const std::string& aFunction)
      : theWarning(aWarningType),theMessage(aMessage),theFunction(aFunction) {}


   WarningType        getWarning()  const { return theWarning; }
   const std::string& getMessage()  const { return theMessage; }
   const std::string& getFunction() const { return theFunction; }

   void setWarning(const WarningType& aWarningType,
                   const std::string& aMessage,
                   const std::string& aFunction)
   {
      theWarning = aWarningType;
      theMessage = aMessage;
      theFunction = aFunction;
   }

private:
   WarningType theWarning;
      //> enumeration of the warning (for application control),
      //<
   std::string theMessage;
      //> string describing the warning.
      //<
   std::string theFunction;
      //> string identifying the function in which the warning occurred.
      //<
};

typedef std::list<Warning> WarningList;

} // namespace csm

#endif // __CSMWARNING_H
