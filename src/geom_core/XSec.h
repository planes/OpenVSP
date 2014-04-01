//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//

// XSec.h: Cross Section Base Class and Derived Classes
// J.R Gloudemans
//
//////////////////////////////////////////////////////////////////////

#if !defined(XSEC__INCLUDED_)
#define XSEC__INCLUDED_

#include "Parm.h"
#include "ParmContainer.h"
#include "Vec3d.h"
#include "VspSurf.h"

#include <string>
#include <vector>
#include <memory>
#include <utility>

using std::string;

class Geom;

class XSec : public ParmContainer
{
public:
    XSec( bool use_left );                                                      // Default Constructor

    enum { POINT, CIRCLE, ELLIPSE, SUPER_ELLIPSE, ROUNDED_RECTANGLE, GENERAL_FUSE, FILE_FUSE,
           FOUR_SERIES, SIX_SERIES, BICONVEX, WEDGE, BEZIER, FILE_AIRFOIL, NUM_XSEC_TYPES
         };

    virtual void ParmChanged( Parm* parm_ptr, int type );
    virtual void Update();

    virtual void SetGroupDisplaySuffix( int num );
    virtual string GetGroupName()
    {
        return m_GroupName;
    }

    virtual void SetRefLength( double len );

    virtual VspCurve& GetUntransformedCurve();
    virtual VspCurve& GetCurve();

    virtual int  GetType()
    {
        return m_Type;
    }

    //==== Copy Between Different Types ====//
    virtual void CopyFrom( XSec* xs );
    virtual xmlNodePtr EncodeXml( xmlNodePtr & node );
    virtual xmlNodePtr DecodeXml( xmlNodePtr & node );

    virtual xmlNodePtr EncodeXSec( xmlNodePtr & node );
    virtual xmlNodePtr DecodeXSec( xmlNodePtr & node );

    virtual double GetWidth()
    {
        return 0.0;
    }
    virtual double GetHeight()
    {
        return 0.0;
    }
    virtual void SetWidthHeight( double w, double h )           {}
    virtual void SetScale( double scale );

    virtual double ComputeArea( int num_pnts );

    void SetTransformation( const Matrix4d &mat, bool center );

    FractionParm m_XLocPercent;
    FractionParm m_YLocPercent;
    FractionParm m_ZLocPercent;

    Parm m_Spin;

    Parm m_XRotate;
    Parm m_YRotate;
    Parm m_ZRotate;

protected:

    Matrix4d m_rotation;
    bool m_center;

    int m_Type;

    string m_RefLengthParmID;
    double m_RefLength;

    string m_GroupName;
    string m_ParentGeomID;

    VspCurve m_Curve;
    VspCurve m_TransformedCurve;

    virtual void ChangeID( string id );
};

//==========================================================================//
//==========================================================================//
//==========================================================================//

class PointXSec : public XSec
{
public:

    PointXSec( bool use_left );

    virtual void Update();

};

//==========================================================================//
//==========================================================================//
//==========================================================================//

class CircleXSec : public XSec
{
public:

    CircleXSec( bool use_left );

    virtual void Update();

    //==== Values to Set/Get When Changing Types ====//
    virtual double GetWidth()
    {
        return m_Diameter();
    }
    virtual double GetHeight()
    {
        return m_Diameter();
    }
    virtual void SetWidthHeight( double w, double h );

    Parm m_Diameter;
};

//==========================================================================//
//==========================================================================//
//==========================================================================//

class EllipseXSec : public XSec
{
public:

    EllipseXSec( bool use_left );

    virtual void Update();

    //==== Values to Set/Get When Changing Types ====//
    virtual double GetWidth()
    {
        return m_Width();
    }
    virtual double GetHeight()
    {
        return m_Height();
    }
    virtual void SetWidthHeight( double w, double h );

    Parm m_Width;
    Parm m_Height;
};

//==========================================================================//
//==========================================================================//
//==========================================================================//

class SuperXSec : public XSec
{
public:

    SuperXSec( bool use_left );

    virtual void Update();

    //==== Values to Set/Get When Changing Types ====//
    virtual double GetWidth()
    {
        return m_Width();
    }
    virtual double GetHeight()
    {
        return m_Height();
    }
    virtual void SetWidthHeight( double w, double h );

    Parm m_Width;
    Parm m_Height;
    Parm m_M;
    Parm m_N;
};

//==========================================================================//
//==========================================================================//
//==========================================================================//

class RoundedRectXSec : public XSec
{
public:

    RoundedRectXSec( bool use_left );

    virtual void Update();

    //==== Values to Set/Get When Changing Types ====//
    virtual double GetWidth()
    {
        return m_Width();
    }
    virtual double GetHeight()
    {
        return m_Height();
    }
    virtual void SetWidthHeight( double w, double h );

    Parm m_Width;
    Parm m_Height;
    Parm m_Radius;
};

//==========================================================================//
//==========================================================================//
//==========================================================================//

class GeneralFuseXSec : public XSec
{
public:

    GeneralFuseXSec( bool use_left );

    virtual void Update();

    //==== Values to Set/Get When Changing Types ====//
    virtual double GetWidth()
    {
        return m_Width();
    }
    virtual double GetHeight()
    {
        return m_Height();
    }
    virtual void SetWidthHeight( double w, double h );

    Parm m_Width;
    Parm m_Height;
    Parm m_MaxWidthLoc;
    Parm m_CornerRad;
    Parm m_TopTanAngle;
    Parm m_BotTanAngle;
    Parm m_TopStr;
    Parm m_BotStr;
    Parm m_UpStr;
    Parm m_LowStr;
};

//==========================================================================//
//==========================================================================//
//==========================================================================//

class FileXSec : public XSec
{
public:

    FileXSec( bool use_left );

    virtual void Update();

    virtual xmlNodePtr EncodeXml( xmlNodePtr & node );
    virtual xmlNodePtr DecodeXml( xmlNodePtr & node );

    //==== Values to Set/Get When Changing Types ====//
    virtual double GetWidth()
    {
        return m_Width();
    }
    virtual double GetHeight()
    {
        return m_Height();
    }
    virtual void SetWidthHeight( double w, double h );
    vector< vec3d > GetUnityFilePnts()
    {
        return m_UnityFilePnts;
    }

    //===== Read File ====//
    bool ReadXsecFile( string file_name );
    void SetPnts( vector< vec3d > & pnt_vec );

    Parm m_Width;
    Parm m_Height;

    string m_FileName;


protected:

    vector< vec3d > m_UnityFilePnts;

    bool ReadOldXSecFile( FILE* file_id );
    bool ReadXSecFile( FILE* file_id );


};





#endif // !defined(XSEC__INCLUDED_)
