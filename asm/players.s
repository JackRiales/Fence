;
; File generated by cc65 v 2.16 - Git N/A
;
	.fopt		compiler,"cc65 v 2.16 - Git N/A"
	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.import		_metaspr
	.export		_META_PLAYERONE
	.export		_players_init
	.export		_players_update
	.export		_players_draw

.segment	"RODATA"

_META_PLAYERONE:
	.byte	$06
	.byte	$00
	.byte	$50
	.byte	$00
	.byte	$06
	.byte	$08
	.byte	$60
	.byte	$00
	.byte	$0E
	.byte	$04
	.byte	$40
	.byte	$00
	.byte	$16
	.byte	$04
	.byte	$41
	.byte	$00
	.byte	$02
	.byte	$00
	.byte	$51
	.byte	$00
	.byte	$80

.segment	"BSS"

.segment	"BSS"
_i:
	.res	1,$00

; ---------------------------------------------------------------
; void __near__ __fastcall__ players_init (__near__ struct $anon-struct-0002 *, unsigned char)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_players_init: near

.segment	"CODE"

;
; {
;
	jsr     pusha
;
; players->sprites[i].x = MAX_X / 2;
;
	ldy     #$02
	lda     (sp),y
	tax
	dey
	lda     (sp),y
	clc
	adc     #$04
	bcc     L001D
	inx
L001D:	sta     ptr1
	stx     ptr1+1
	ldx     #$00
	dey
	lda     (sp),y
	jsr     aslax2
	clc
	adc     ptr1
	sta     ptr1
	txa
	adc     ptr1+1
	sta     ptr1+1
	lda     #$80
	sta     (ptr1),y
;
; players->sprites[i].y = MAX_Y / 2;
;
	ldy     #$02
	lda     (sp),y
	tax
	dey
	lda     (sp),y
	clc
	adc     #$04
	bcc     L0021
	inx
L0021:	sta     ptr1
	stx     ptr1+1
	ldx     #$00
	lda     (sp,x)
	jsr     aslax2
	clc
	adc     ptr1
	sta     ptr1
	txa
	adc     ptr1+1
	sta     ptr1+1
	lda     #$77
	ldy     #$01
	sta     (ptr1),y
;
; players->sprites[i].index_buffer = (u8*)META_PLAYERONE;
;
	iny
	lda     (sp),y
	tax
	dey
	lda     (sp),y
	clc
	adc     #$04
	bcc     L0025
	inx
L0025:	sta     ptr1
	stx     ptr1+1
	ldx     #$00
	lda     (sp,x)
	jsr     aslax2
	clc
	adc     ptr1
	sta     ptr1
	txa
	adc     ptr1+1
	sta     ptr1+1
	lda     #<(_META_PLAYERONE)
	iny
	sta     (ptr1),y
	iny
	lda     #>(_META_PLAYERONE)
	sta     (ptr1),y
;
; }
;
	jmp     incsp3

.endproc

; ---------------------------------------------------------------
; void __near__ __fastcall__ players_update (__near__ struct $anon-struct-0002 *)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_players_update: near

.segment	"CODE"

;
; {
;
	jsr     pushax
;
; }
;
	jmp     incsp2

.endproc

; ---------------------------------------------------------------
; void __near__ __fastcall__ players_draw (__near__ struct $anon-struct-0002 *, __near__ unsigned char *)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_players_draw: near

.segment	"CODE"

;
; {
;
	jsr     pushax
;
; for (i = 0; i < 2; ++i)
;
	lda     #$00
	sta     _i
L0037:	lda     _i
	cmp     #$02
	bcs     L002B
;
; metaspr(&players->sprites[i], oam_ptr);
;
	ldy     #$03
	lda     (sp),y
	tax
	dey
	lda     (sp),y
	clc
	adc     #$04
	bcc     L0034
	inx
L0034:	sta     ptr1
	stx     ptr1+1
	ldx     #$00
	lda     _i
	jsr     aslax2
	clc
	adc     ptr1
	pha
	txa
	adc     ptr1+1
	tax
	pla
	jsr     pushax
	ldy     #$03
	lda     (sp),y
	tax
	dey
	lda     (sp),y
	jsr     _metaspr
;
; for (i = 0; i < 2; ++i)
;
	inc     _i
	jmp     L0037
;
; }
;
L002B:	jmp     incsp4

.endproc
