//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2005, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// pgTablespace.h - PostgreSQL Tablespace
//
//////////////////////////////////////////////////////////////////////////

#ifndef PGTABLESPACE_H
#define PGTABLESPACE_H


#include "pgServer.h"

class pgTablespaceFactory : public pgServerObjFactory
{
public:
    pgTablespaceFactory();
    virtual dlgProperty *CreateDialog(frmMain *frame, pgObject *node, pgObject *parent);
    virtual pgObject *CreateObjects(pgCollection *obj, ctlTree *browser, const wxString &restr=wxEmptyString);
    virtual pgCollection *CreateCollection(pgObject *obj);
};
extern pgTablespaceFactory tablespaceFactory;


class pgTablespace : public pgServerObject
{
public:
    pgTablespace(const wxString& newName = wxT(""));
    ~pgTablespace();

    void ShowTreeDetail(ctlTree *browser, frmMain *form=0, ctlListView *properties=0, ctlSQLBox *sqlPane=0);
    void ShowStatistics(frmMain *form, ctlListView *statistics);
    void ShowReferencedBy(frmMain *form, ctlListView *referencedBy, const wxString &where=wxEmptyString);
    
    wxString GetLocation() const { return location; };
    void iSetLocation(const wxString& newVal) { location = newVal; }
    
    bool DropObject(wxFrame *frame, ctlTree *browser, bool cascaded);
    bool RequireDropConfirm() { return true; }
    pgConn *connection();

    wxString GetSql(ctlTree *browser);
    pgObject *Refresh(ctlTree *browser, const wxTreeItemId item);

private:
    wxString location;
};


class pgTablespaceCollection : public pgServerObjCollection
{
public:
    pgTablespaceCollection(pgaFactory *factory, pgServer *sv);
    void ShowStatistics(frmMain *form, ctlListView *statistics);
};


#endif
