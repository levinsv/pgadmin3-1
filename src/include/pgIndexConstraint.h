//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2005, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// pgIndexConstraint.h PostgreSQL Index Constraint: PK, Unique
//
//////////////////////////////////////////////////////////////////////////


#ifndef __PG_INDEXCONSTRAINT
#define __PG_INDEXCONSTRAINT

#include "pgIndex.h"

class pgIndexConstraint : public pgIndex
{
public:
    void ShowTreeDetail(ctlTree *browser, frmMain *form=0, ctlListView *properties=0, ctlSQLBox *sqlPane=0);
    bool DropObject(wxFrame *frame, ctlTree *browse, bool cascadedr);
    wxString GetDefinition();
    wxString GetCreate();
    wxString GetSql(ctlTree *browser);
    wxString GetHelpPage(bool forCreate) const { return wxT("pg/sql-altertable"); }

protected:
    pgIndexConstraint(pgSchema *newSchema, const wxString& newName, int type)
        : pgIndex(newSchema, newName, type) {}
};


class pgPrimaryKey : public pgIndexConstraint
{
public:
    pgPrimaryKey(pgSchema *newSchema, const wxString& newName = wxT(""))
        : pgIndexConstraint(newSchema, newName, PG_PRIMARYKEY) {}

    bool CanCreate() { return false; }
    int GetIconId() { return PGICON_PRIMARYKEY; }
    static pgObject *ReadObjects(pgCollection *collection, ctlTree *browser, const wxString &where=wxT(""));
};

class pgUnique : public pgIndexConstraint
{
public:
    pgUnique(pgSchema *newSchema, const wxString& newName = wxT(""))
        : pgIndexConstraint(newSchema, newName, PG_UNIQUE) {}

    int GetIconId() { return PGICON_UNIQUE; }
    static pgObject *ReadObjects(pgCollection *collection, ctlTree *browser, const wxString &where=wxT(""));
};


#endif
