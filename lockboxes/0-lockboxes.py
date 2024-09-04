#!/usr/bin/python3
"""
lockboxes/0-lockboxes.py
"""


def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened.
    """

    boxes_opened_status = [False for _ in boxes]
    boxes_opened_status[0] = True

    while True:

        new_boxes_opened_status = boxes_opened_status.copy()

        for box_index, box_is_opened in enumerate(boxes_opened_status):
            if not box_is_opened:
                continue

            for box_key in boxes[box_index]:

                try:
                    new_boxes_opened_status[box_key] = True
                except IndexError:
                    pass

        if new_boxes_opened_status == boxes_opened_status:
            break

        boxes_opened_status = new_boxes_opened_status

    return all(boxes_opened_status)