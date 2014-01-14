/*
**********************************************************************
* Copyright (c) 2004-2006, International Business Machines
* Corporation and others.  All Rights Reserved.
**********************************************************************
* Author: Alan Liu
* Created: April 26, 2004
* Since: ICU 3.0
**********************************************************************
*/
#ifndef __MEASUREUNIT_H__
#define __MEASUREUNIT_H__

#include "unicode/utypes.h"
#include "unicode/unistr.h"

/**
 * \file 
 * \brief C++ API: A unit for measuring a quantity.
 */
 
U_NAMESPACE_BEGIN

/**
 * A unit such as length, mass, volume, currency, etc.  A unit is
 * coupled with a numeric amount to produce a Measure.
 *
 * @author Alan Liu
 * @stable ICU 3.0
 */
class U_I18N_API MeasureUnit: public UObject {
 public:

    /**
     * Default constructor.
     * @stable ICU 3.0
     */
    MeasureUnit() : fTypeId(0), fSubTypeId(0) { 
        fCurrency[0] = 0;
    }
    
    /**
     * Copy constructor.
     * @draft ICU 53
     */
    MeasureUnit(const MeasureUnit &other);
        
    /**
     * Assignment operator.
     * @draft ICU 53.
     */
    MeasureUnit &operator=(const MeasureUnit &other);

    /**
     * Return a polymorphic clone of this object.  The result will
     * have the same class as returned by getDynamicClassID().
     * @stable ICU 3.0
     */
    virtual UObject* clone() const;

    /**
     * Destructor
     * @stable ICU 3.0
     */
    virtual ~MeasureUnit();

    /**
     * Equality operator.  Return true if this object is equal
     * to the given object.
     * @stable ICU 3.0
     */
    virtual UBool operator==(const UObject& other) const;

    /**
     * Get the type.
     * @draft ICU 53
     */
    const char *getType() const;

    /**
     * Get the sub type.
     * @draft ICU 53
     */
    const char *getSubtype() const;

    /**
     * Internal. ICU use only.
     * @draft ICU 53
     */
    int32_t getIndex() const;

    /**
     * getAvailable gets all of the available units.
     * If there are too many units to fit into destCapacity then the
     * error code is set to U_BUFFER_OVERFLOW_ERROR.
     *
     * @param destCapacity number of MeasureUnit instances available at dest.
     * @param dest destination buffer.
     * @param errorCode ICU error code.
     * @return number of available units.
     * @draft ICU 53
     */
    static int32_t getAvailable(
            int32_t destCapacity,
            MeasureUnit *dest,
            UErrorCode &errorCode);

    /**
     * getAvailable gets all of the available units for a specific type.
     * If there are too many units to fit into destCapacity then the
     * error code is set to U_BUFFER_OVERFLOW_ERROR.
     *
     * @param type the type
     * @param destCapacity number of MeasureUnit instances available at dest.
     * @param dest destination buffer.
     * @param errorCode ICU error code.
     * @return number of available units for type.
     * @draft ICU 53
     */
    static int32_t getAvailable(
            const char *type,
            int32_t destCapacity,
            MeasureUnit *dest,
            UErrorCode &errorCode);

    /**
     * getAvailableTypes gets all of the available types.
     * If there are too many types to fit into destCapacity then the
     * error code is set to U_BUFFER_OVERFLOW_ERROR.
     *
     * @param dest destination buffer.
     * @param destCapacity number of const char * instances available at dest.
     * @param errorCode ICU error code.
     * @return number of types.
     * @draft ICU 53
     */
    static int32_t getAvailableTypes(
            int32_t destCapacity,
            const char **dest,
            UErrorCode &errorCode);

    /**
     * Internal. ICU use only.
     * @draft ICU 53
     */
    static int32_t getMaxIndex();

    /** Constant for unit of acceleration: g-force */
    static MeasureUnit *createGforce(UErrorCode &status);

    /** Constant for unit of angle: arc-minute */
    static MeasureUnit *createArcminute(UErrorCode &status);

    /** Constant for unit of angle: arc-second */
    static MeasureUnit *createArcsecond(UErrorCode &status);

    /** Constant for unit of angle: degree */
    static MeasureUnit *createDegree(UErrorCode &status);

    /** Constant for unit of area: acre */
    static MeasureUnit *createAcre(UErrorCode &status);

    /** Constant for unit of area: hectare */
    static MeasureUnit *createHectare(UErrorCode &status);

    /** Constant for unit of area: square-foot */
    static MeasureUnit *createSquarefoot(UErrorCode &status);

    /** Constant for unit of area: square-kilometer */
    static MeasureUnit *createSquarekilometer(UErrorCode &status);

    /** Constant for unit of area: square-meter */
    static MeasureUnit *createSquaremeter(UErrorCode &status);

    /** Constant for unit of area: square-mile */
    static MeasureUnit *createSquaremile(UErrorCode &status);

    /** Constant for unit of duration: day */
    static MeasureUnit *createDay(UErrorCode &status);

    /** Constant for unit of duration: hour */
    static MeasureUnit *createHour(UErrorCode &status);

    /** Constant for unit of duration: millisecond */
    static MeasureUnit *createMillisecond(UErrorCode &status);

    /** Constant for unit of duration: minute */
    static MeasureUnit *createMinute(UErrorCode &status);

    /** Constant for unit of duration: month */
    static MeasureUnit *createMonth(UErrorCode &status);

    /** Constant for unit of duration: second */
    static MeasureUnit *createSecond(UErrorCode &status);

    /** Constant for unit of duration: week */
    static MeasureUnit *createWeek(UErrorCode &status);

    /** Constant for unit of duration: year */
    static MeasureUnit *createYear(UErrorCode &status);

    /** Constant for unit of length: centimeter */
    static MeasureUnit *createCentimeter(UErrorCode &status);

    /** Constant for unit of length: foot */
    static MeasureUnit *createFoot(UErrorCode &status);

    /** Constant for unit of length: inch */
    static MeasureUnit *createInch(UErrorCode &status);

    /** Constant for unit of length: kilometer */
    static MeasureUnit *createKilometer(UErrorCode &status);

    /** Constant for unit of length: light-year */
    static MeasureUnit *createLightyear(UErrorCode &status);

    /** Constant for unit of length: meter */
    static MeasureUnit *createMeter(UErrorCode &status);

    /** Constant for unit of length: mile */
    static MeasureUnit *createMile(UErrorCode &status);

    /** Constant for unit of length: millimeter */
    static MeasureUnit *createMillimeter(UErrorCode &status);

    /** Constant for unit of length: picometer */
    static MeasureUnit *createPicometer(UErrorCode &status);

    /** Constant for unit of length: yard */
    static MeasureUnit *createYard(UErrorCode &status);

    /** Constant for unit of mass: gram */
    static MeasureUnit *createGram(UErrorCode &status);

    /** Constant for unit of mass: kilogram */
    static MeasureUnit *createKilogram(UErrorCode &status);

    /** Constant for unit of mass: ounce */
    static MeasureUnit *createOunce(UErrorCode &status);

    /** Constant for unit of mass: pound */
    static MeasureUnit *createPound(UErrorCode &status);

    /** Constant for unit of power: horsepower */
    static MeasureUnit *createHorsepower(UErrorCode &status);

    /** Constant for unit of power: kilowatt */
    static MeasureUnit *createKilowatt(UErrorCode &status);

    /** Constant for unit of power: watt */
    static MeasureUnit *createWatt(UErrorCode &status);

    /** Constant for unit of pressure: hectopascal */
    static MeasureUnit *createHectopascal(UErrorCode &status);

    /** Constant for unit of pressure: inch-hg */
    static MeasureUnit *createInchhg(UErrorCode &status);

    /** Constant for unit of pressure: millibar */
    static MeasureUnit *createMillibar(UErrorCode &status);

    /** Constant for unit of speed: kilometer-per-hour */
    static MeasureUnit *createKilometerperhour(UErrorCode &status);

    /** Constant for unit of speed: meter-per-second */
    static MeasureUnit *createMeterpersecond(UErrorCode &status);

    /** Constant for unit of speed: mile-per-hour */
    static MeasureUnit *createMileperhour(UErrorCode &status);

    /** Constant for unit of temperature: celsius */
    static MeasureUnit *createCelsius(UErrorCode &status);

    /** Constant for unit of temperature: fahrenheit */
    static MeasureUnit *createFahrenheit(UErrorCode &status);

    /** Constant for unit of volume: cubic-kilometer */
    static MeasureUnit *createCubickilometer(UErrorCode &status);

    /** Constant for unit of volume: cubic-mile */
    static MeasureUnit *createCubicmile(UErrorCode &status);

    /** Constant for unit of volume: liter */
    static MeasureUnit *createLiter(UErrorCode &status);

 protected:

    /**
     * For ICU use only.
     * @internal ICU 53
     */
    void initTime(const char *timeId);

    /**
     * For ICU use only.
     * @internal ICU 53
     */
    void initCurrency(const char *isoCurrency);
private:
    int32_t fTypeId;
    int32_t fSubTypeId;
    char fCurrency[4];

    MeasureUnit(int32_t typeId, int32_t subTypeId) : fTypeId(typeId), fSubTypeId(subTypeId) {
        fCurrency[0] = 0;
    }
    void setTo(int32_t typeId, int32_t subTypeId);
    int32_t getOffset() const;
    static MeasureUnit *create(int typeId, int subTypeId, UErrorCode &status);

};

U_NAMESPACE_END

#endif // __MEASUREUNIT_H__
