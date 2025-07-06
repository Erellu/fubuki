# Fubuki's contribution guidelines

> [!IMPORTANT]
> The following guidelines are for _developpers_.
> It does not provide any documentation of Fubuki's API.

The goal of this file is to provide an overview of how to format a contribution.

> [!IMPORTANT]
> **These guidelines are not set in stone**.
> They are susceptible to change if they do not benefit the project.
> To discuss a guideline change, **please open an issue**.

## Nomenclature

This file uses the following nomenclature:

- **Use/Provide/Add/Be/(any verb)**: do that. No need to explain why you did this like that.
- **DO NOT use/provide/add/(_any verb_)**: don't do that. A contribution that does this is likely to be rejected. If done, will be asked to motivate the choices.
- **Prefer**: Attempt to do. Don't do if necessary, document why. Mostly related to design decisions.
- **Avoid**: attempt not to do. Do if necessary, document why. Mostly related to design decisions.

Each section name is followed by a tag of the format:

> **`[contrib.category.subcategory]`**

Use this to refer to a particular section when writing an issue. 
To refer to a particular point, use **`[contrib.category.subcategory#number]`**. 
For example: **`[contrib.issues#1]`**  refers to the first rule related to contributions of the category "Issues".

## Language `[contrib.lang]`

1. **Use** English to communicate in issue threads, Pull Requests, commit comments and other participating places.
2. **Use** whatever flavour of English you are the most familiar with to communicate on GitHub.
3. **Prefer** British English _in code_.

## Workflow `[contrib.workflow]`

To report a problem, request a feature or an enhancement on an existing feature:

1. **Open** an issue.
    - Pick one of the available templates and fill it accordingly.
    - If no template matches, fill an issue from scratch.
2. **Wait** for a maintainer answer.

To provide a contribution through a pull request:

1. **Open** an issue.
    - Pick one of the following templates: `Bug report`/`Enhancement`/`Feature`.
    - Fill the `Proposal` with an overview of your solution design.
2. **Wait** for an answer from a maintainer.

If your design and solution is accepted:

1. **Open** a pull request.
    - Apply and fill [the template](https://github.com/Erellu/fubuki/blob/master/.github/PULL_REQUEST_TEMPLATE/pull_request_template.md).
2. **Wait** for review from a maintainer.
3. **Discuss** proposed changes with the reviewer.
    - ***A reviewer's word is NOT ABSOLUTE***.
4. Once all the checks passed, your PR is merged.

## Issues`[contrib.issues]`

1. **Open** issues to request features, propose enhancements, report a bug, provide feedback... Or anything that relates to Fubuki.

Maintainers:

1. **Create** a branch to work on an existing.
2. **Mark** an issue as `status:doing` while working on it.
3. **Tag** issues with the appropriate tags (`theme:fuyu`, etc.)

## Pull requests `[contrib.pr]`

1. **Make sure** your pull request has an associated issue.
2. **Make sure** your pull request has a `Closes #issue-number`.
3. **Mark** your pull request as Draft if it is not ready for review.

Maintainers:

1. **Tag** issues with the appropriate tags (`theme:fuyu`, etc.)
2. **Mark** a pull request as `status:reviewing` while reviewing on it.
