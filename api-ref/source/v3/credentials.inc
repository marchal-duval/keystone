.. -*- rst -*-

=============
 Credentials
=============

In exchange for a set of authentication credentials that the user
submits, the Identity service generates and returns a token. A
token represents the authenticated identity of a user and,
optionally, grants authorization on a specific project or domain.

You can list all credentials, and create, show details for, update,
and delete a credential.


Create credential
=================

.. rest_method::  POST /v3/credentials

Creates a credential.

The following example shows how to create an EC2-style credential.
The credential blob is a string that contains a JSON-serialized
dictionary with the ``access`` and ``secret`` keys. This format is
required when you specify the ``ec2`` type. To specify other
credentials, such as ``access_key``, change the type and contents
of the data blob.

Error response codes:201,413,415,405,404,403,401,400,503,409,

Request
-------

.. rest_parameters:: parameters.yaml

   - credential: credential
   - project_id: project_id
   - type: type
   - blob: blob
   - user_id: user_id

Request Example
---------------

.. literalinclude:: ./samples/admin/credential-create-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - credential: credential
   - user_id: user_id
   - links: links
   - blob: blob
   - project_id: project_id
   - type: type
   - id: id


List credentials
================

.. rest_method::  GET /v3/credentials

Lists all credentials.

Optionally, you can include the ``user_id`` query parameter in the
URI to filter the response by a user.

Normal response codes: 200
Error response codes:413,405,404,403,401,400,503,

Request
-------

.. rest_parameters:: parameters.yaml

   - user_id: user_id

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - user_id: user_id
   - links: links
   - blob: blob
   - credentials: credentials
   - project_id: project_id
   - type: type
   - id: id

Response Example
----------------

.. literalinclude:: ./samples/admin/credentials-list-response.json
   :language: javascript


Show credential details
=======================

.. rest_method::  GET /v3/credentials/{credential_id}

Shows details for a credential.

Normal response codes: 200
Error response codes:413,405,404,403,401,400,503,

Request
-------

.. rest_parameters:: parameters.yaml

   - credential_id: credential_id

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - credential: credential
   - user_id: user_id
   - links: links
   - blob: blob
   - project_id: project_id
   - type: type
   - id: id

Response Example
----------------

.. literalinclude:: ./samples/admin/credential-show-response.json
   :language: javascript


Update credential
=================

.. rest_method::  PATCH /v3/credentials/{credential_id}

Updates a credential.

Normal response codes: 200
Error response codes:413,415,405,404,403,401,400,503,409,

Request
-------

.. rest_parameters:: parameters.yaml

   - credential: credential
   - project_id: project_id
   - type: type
   - blob: blob
   - user_id: user_id
   - credential_id: credential_id

Request Example
---------------

.. literalinclude:: ./samples/admin/credential-update-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - credential: credential
   - user_id: user_id
   - links: links
   - blob: blob
   - project_id: project_id
   - type: type
   - id: id

Response Example
----------------

.. literalinclude:: ./samples/admin/credential-update-response.json
   :language: javascript


Delete credential
=================

.. rest_method::  DELETE /v3/credentials/{credential_id}

Deletes a credential.

Error response codes:204,413,415,405,404,403,401,400,503,409,

Request
-------

.. rest_parameters:: parameters.yaml

   - credential_id: credential_id
